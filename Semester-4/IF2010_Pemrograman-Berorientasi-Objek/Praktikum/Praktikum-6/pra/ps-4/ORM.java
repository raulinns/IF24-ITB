import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class ORM {

    /**
     * Mencetak skema (nama tabel dan kolom-kolom) dari kelas yang diberikan.
     * Hanya field yang beranotasi @ColumnName yang ditampilkan.
     *
     * Format output:
     *   Table: <nama_tabel>
     *   Columns:
     *     - <nama_kolom> [PRIMARY KEY]   <- jika primaryKey = true
     *     - <nama_kolom>
     */
    public static void schema(Class<?> clazz) {
        TableName tableName = clazz.getAnnotation(TableName.class);

        System.out.println("Table: " + tableName.value());
        System.out.println("Columns:");

        for (Field field : clazz.getDeclaredFields()) {
            ColumnName columnName = field.getAnnotation(ColumnName.class);

            if (columnName != null) {
                if (columnName.primaryKey()) {
                    System.out.println("  - " + columnName.value() + " [PRIMARY KEY]");
                } else {
                    System.out.println("  - " + columnName.value());
                }
            }
        }
    }

    /**
     * Membuat instance dari kelas yang diberikan menggunakan Reflection.
     * values[] berisi nilai-nilai untuk field beranotasi @ColumnName sesuai urutan deklarasi.
     * Tipe yang perlu didukung: String, int, double.
     *
     * Setelah semua field diisi, panggil semua method yang beranotasi
     * @Hook(when = Hook.When.POST_LOAD) menggunakan method.invoke().
     */
    public static Object createInstance(Class<?> clazz, String[] values) throws Exception {
        Object obj = clazz.getDeclaredConstructor().newInstance();

        int index = 0;
        for (Field field : clazz.getDeclaredFields()) {
            ColumnName columnName = field.getAnnotation(ColumnName.class);

            if (columnName != null) {
                field.setAccessible(true);

                String value = values[index];
                Class<?> type = field.getType();

                if (type == String.class) {
                    field.set(obj, value);
                } else if (type == int.class) {
                    field.setInt(obj, Integer.parseInt(value));
                } else if (type == double.class) {
                    field.setDouble(obj, Double.parseDouble(value));
                }

                index++;
            }
        }

        for (Method method : clazz.getDeclaredMethods()) {
            Hook hook = method.getAnnotation(Hook.class);

            if (hook != null && hook.when() == Hook.When.POST_LOAD) {
                method.setAccessible(true);
                method.invoke(obj);
            }
        }

        return obj;
    }

    /**
     * Mencetak pernyataan INSERT SQL berdasarkan objek yang diberikan.
     *
     * Sebelum mencetak SQL, panggil semua method yang beranotasi
     * @Hook(when = Hook.When.PRE_INSERT) menggunakan method.invoke().
     * Jika salah satu method tersebut melempar exception (InvocationTargetException),
     * cetak "Gagal insert: <pesan exception>" dan JANGAN cetak SQL INSERT.
     *
     * Format output (jika tidak ada exception):
     *   INSERT INTO <nama_tabel> (<col1>, <col2>, ...) VALUES (<val1>, <val2>, ...)
     * Keterangan: nilai String diapit tanda kutip satu (' '),
     *             nilai numerik (int/double) ditulis apa adanya.
     */
    public static void insert(Object obj) throws Exception {
        Class<?> clazz = obj.getClass();

        try {
            for (Method method : clazz.getDeclaredMethods()) {
                Hook hook = method.getAnnotation(Hook.class);

                if (hook != null && hook.when() == Hook.When.PRE_INSERT) {
                    method.setAccessible(true);
                    method.invoke(obj);
                }
            }
        } catch (InvocationTargetException e) {
            System.out.println("Gagal insert: " + e.getCause().getMessage());
            return;
        }

        TableName tableName = clazz.getAnnotation(TableName.class);
        StringBuilder columns = new StringBuilder();
        StringBuilder values = new StringBuilder();
        boolean first = true;

        for (Field field : clazz.getDeclaredFields()) {
            ColumnName columnName = field.getAnnotation(ColumnName.class);

            if (columnName != null) {
                field.setAccessible(true);

                if (!first) {
                    columns.append(", ");
                    values.append(", ");
                }

                columns.append(columnName.value());

                Object value = field.get(obj);
                if (value instanceof String) {
                    values.append("'").append(value).append("'");
                } else {
                    values.append(value);
                }

                first = false;
            }
        }

        System.out.println("INSERT INTO " + tableName.value()
                + " (" + columns + ") VALUES (" + values + ")");
    }

    /**
     * Mencetak pernyataan DELETE SQL berdasarkan objek yang diberikan.
     *
     * Sebelum mencetak SQL, panggil semua method yang beranotasi
     * @Hook(when = Hook.When.PRE_DELETE) menggunakan method.invoke().
     * Jika salah satu method tersebut melempar exception (InvocationTargetException),
     * cetak "Gagal delete: <pesan exception>" dan JANGAN cetak SQL DELETE.
     *
     * Format output (jika tidak ada exception):
     *   DELETE FROM <nama_tabel> WHERE <pk_kolom> = <pk_nilai>
     * Keterangan: pk_nilai bertipe String diapit tanda kutip satu (' '),
     *             pk_nilai bertipe numerik ditulis apa adanya.
     * Gunakan field pertama yang memiliki @ColumnName(primaryKey = true) sebagai WHERE clause.
     */
    public static void delete(Object obj) throws Exception {
        Class<?> clazz = obj.getClass();

        try {
            for (Method method : clazz.getDeclaredMethods()) {
                Hook hook = method.getAnnotation(Hook.class);

                if (hook != null && hook.when() == Hook.When.PRE_DELETE) {
                    method.setAccessible(true);
                    method.invoke(obj);
                }
            }
        } catch (InvocationTargetException e) {
            System.out.println("Gagal delete: " + e.getCause().getMessage());
            return;
        }

        TableName tableName = clazz.getAnnotation(TableName.class);

        for (Field field : clazz.getDeclaredFields()) {
            ColumnName columnName = field.getAnnotation(ColumnName.class);

            if (columnName != null && columnName.primaryKey()) {
                field.setAccessible(true);

                Object value = field.get(obj);
                String pkValue;

                if (value instanceof String) {
                    pkValue = "'" + value + "'";
                } else {
                    pkValue = String.valueOf(value);
                }

                System.out.println("DELETE FROM " + tableName.value()
                        + " WHERE " + columnName.value() + " = " + pkValue);
                return;
            }
        }
    }
}

