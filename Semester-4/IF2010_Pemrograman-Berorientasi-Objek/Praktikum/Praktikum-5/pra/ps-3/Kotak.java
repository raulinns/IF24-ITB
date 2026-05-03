import java.util.ArrayList;

public class Kotak<T extends Barang> {
    private ArrayList<T> items;
    private int kapasitas;

    public Kotak(int kapasitas) {
        this.kapasitas = kapasitas;
        this.items = new ArrayList<>();
    }

    public boolean tambah(T item) {
        if (this.penuh()) {
            return false;
        } else {
            this.items.add(item);
            return true;
        }
    }

    public T ambil() {
        if (kosong()) {
            return null;
        } else {
            return this.items.remove(this.items.size() - 1);
        }
    }

    public T lihat(int index) {
        if (index < 0 || index >= this.items.size()) {
            return null;
        } else {
            return this.items.get(index);
        }
    }

    public int jumlah() {
        return this.items.size();
    }

    public int kapasitas() {
        return this.kapasitas;
    }

    public boolean penuh() {
        return this.items.size() == this.kapasitas;
    }

    public boolean kosong() {
        return this.items.isEmpty();
    }
}
