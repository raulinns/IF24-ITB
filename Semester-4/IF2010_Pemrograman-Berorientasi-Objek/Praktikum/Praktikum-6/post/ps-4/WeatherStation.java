import java.util.ArrayList;
import java.util.List;

public class WeatherStation {
    // TODO:
    // Deklarasikan field berikut:
    private List<WeatherObserver> observers;
    private double temperature;
    private double humidity;

    public WeatherStation() {
        // Inisialisasi observers sebagai ArrayList kosong.
        // Set temperature = 0.0 dan humidity = 0.0.
        observers = new ArrayList<>();
        temperature = 0.0;
        humidity = 0.0;
    }

    public void addObserver(WeatherObserver observer) {
        // Tambahkan observer ke dalam daftar observers.
        observers.add(observer);
    }

    public boolean removeObserver(String name) {
        // Cari observer dengan nama yang sesuai di dalam daftar.
        // Jika ditemukan, hapus dan kembalikan true.
        // Jika tidak ditemukan, kembalikan false.
        return observers.removeIf(observer -> observer.getName().equals(name));
    }

    public boolean hasObserver(String name) {
        // Kembalikan true jika terdapat observer dengan nama tersebut
        // di dalam daftar, false jika tidak.
        for (WeatherObserver o : observers) {
            if (o.getName().equals(name)) return true;
        }

        return false;
    }

    public void setMeasurements(double temperature, double humidity) {
        // Perbarui nilai temperature dan humidity.
        // Setelah diperbarui, panggil notifyObservers() untuk
        // memberitahu semua observer yang terdaftar.
        
        this.temperature = temperature;
        this.humidity = humidity;
        notifyObservers();
    }

    private void notifyObservers() {
        // Iterasi seluruh observer dalam daftar (sesuai urutan pendaftaran)
        // dan panggil update(temperature, humidity) pada masing-masing observer.
        
        for (WeatherObserver o : observers) {
            o.update(temperature, humidity);
        }
    }

    public double getTemperature() {
        // Kembalikan nilai temperature saat ini.
        return temperature;
    }

    public double getHumidity() {
        // Kembalikan nilai humidity saat ini.

        return humidity;
    }

    public int getObserverCount() {
        // Kembalikan jumlah observer yang saat ini terdaftar.

        return observers.size();
    }
}
