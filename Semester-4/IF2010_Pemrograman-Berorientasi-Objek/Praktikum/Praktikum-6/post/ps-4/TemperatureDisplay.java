public class TemperatureDisplay implements WeatherObserver {
    private String name;

    public TemperatureDisplay(String name) {
        // Simpan nama yang diberikan ke field name.
        this.name = name;
    }

    @Override
    public void update(double temperature, double humidity) {
        // Cetak baris berikut ke System.out:
        // "Display <name>: Suhu <temperature>"
        //
        // Format temperature menggunakan satu angka desimal (%.1f).
        // Contoh: "Display TempA: Suhu 25.0"
        System.out.printf("Display " + name + ": Suhu %.1f\n", temperature);
    }

    @Override
    public String getName() {
        // Kembalikan nama tampilan ini.

        return name;
    }
}
