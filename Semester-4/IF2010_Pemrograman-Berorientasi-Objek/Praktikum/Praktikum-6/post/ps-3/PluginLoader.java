import java.util.List;
import java.util.Arrays;


public class PluginLoader {

    /**
     * Me-load kelas plugin secara dinamis berdasarkan nama kelas yang diberikan.
     * Kelas yang di-load harus merupakan implementasi dari interface Plugin.
     * Jika kelas tersebut tidak mengimplementasikan interface Plugin, method ini
     * harus melempar IllegalArgumentException dengan pesan:
     * "Kelas <className> tidak mengimplementasikan interface Plugin"
     * 
     * @param className Nama lengkap kelas yang akan di-load.
     * @return Instance dari kelas plugin yang berhasil di-load.
     * @throws Exception Jika terjadi error saat proses pemuatan kelas atau instansiasi.
     */
    public static Plugin loadPlugin(String className) throws Exception {
        Class<?> c = Class.forName(className);

        Object instance = c.getDeclaredConstructor().newInstance();

        if (instance instanceof Plugin) {
            return (Plugin) instance;
        } else {
            throw new IllegalArgumentException("Kelas " + c.getName() + " tidak mengimplementasikan interface Plugin");
        }
    }
}
