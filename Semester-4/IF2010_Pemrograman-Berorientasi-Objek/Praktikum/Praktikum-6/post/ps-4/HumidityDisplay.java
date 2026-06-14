public class HumidityDisplay implements WeatherObserver {
    private String name;

    public HumidityDisplay(String name) {
        // Simpan nama yang diberikan ke field name.
        this.name = name;
    }

    @Override
    public void update(double temperature, double humidity) {
        // Cetak baris berikut ke System.out:
        // "Display <name>: Kelembaban <humidity>%"
        //
        // Format humidity menggunakan satu angka desimal (%.1f).
        // Contoh: "Display HumidA: Kelembaban 60.0%"
        System.out.printf("Display " + name + ": Kelembaban %.1f%%\n", humidity);
    }

    @Override
    public String getName() {
        // Kembalikan nama tampilan ini.
        return name;
    }
}
