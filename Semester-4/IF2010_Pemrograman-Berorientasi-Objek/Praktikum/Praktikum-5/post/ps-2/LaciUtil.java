public class LaciUtil {
    public static <T> void tukar(Laci<T> laci, int i, int j) {
        if (i < 1 || i > laci.ukuran() || j < 1 || j > laci.ukuran()) {
            return;
        }
        T temp = laci.ambil(i);
        laci.set(i, laci.ambil(j));
        laci.set(j, temp);
    }

    public static <T extends Comparable<T>> T terbesar(Laci<T> laci) {
        if (laci.ukuran() == 0) return null;
        T max = laci.ambil(1);
        for (int i = 2; i <= laci.ukuran(); i++) {
            T item = laci.ambil(i);
            if (item != null && item.compareTo(max) > 0) {
                max = item;
            }
        }
        return max;
    }
}
