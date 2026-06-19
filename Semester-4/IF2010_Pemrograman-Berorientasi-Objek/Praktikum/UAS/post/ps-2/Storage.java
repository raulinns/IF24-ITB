import java.util.LinkedHashMap;
import java.util.Map;
import java.util.List;
import java.util.ArrayList;
import java.util.HashSet;

public class Storage<T> {
    public Map<String, T> data;
    private int capacity;

    public Storage(int capacity) {
        this.capacity = capacity;
        this.data = new LinkedHashMap<>();
    }

    public void store(String id, T item) throws StorageFullException, DuplicateIdException {
        // Tambahkan item ke dalam data dengan id sebagai key.
        // Jika kapasitas sudah penuh, lemparkan StorageFullException.
        // Jika kapasitas belum penuh namun id sudah ada di dalam data, lemparkan DuplicateIdException.
        if (this.getSize() >= this.getCapacity()) {
            throw new StorageFullException();
        }
        
        if (data.containsKey(id)) {
            throw new DuplicateIdException(id.toString());
        }

        data.put(id, item);
    }

    public T retrieve(String id) throws DataNotFoundException {
        // Kembalikan item yang sesuai dengan id.
        // Jika id tidak ditemukan, lemparkan DataNotFoundException.
        if (!data.containsKey(id)) {
            throw new DataNotFoundException(id.toString());
        }

        return data.get(id);
    }
    
    public void remove(String id) throws DataNotFoundException  {
        // Hapus item dengan id dari dalam data.
        // Jika id tidak ditemukan, lemparkan DataNotFoundException.
        if (!data.containsKey(id)) {
            throw new DataNotFoundException(id.toString());
        }

        T removedObject = data.remove(id);
    }

    public List<T> getAll() {
        // Kembalikan semua item di dalam data dalam bentuk List.
        List<T> l = new ArrayList<>(data.values());

        return l;
    }
    
    public int getCapacity() {
        return this.capacity;
    }
    
    public int getSize() {
        if (this.data == null) {
            return 0;
        }
        return this.data.size();
    }
}
