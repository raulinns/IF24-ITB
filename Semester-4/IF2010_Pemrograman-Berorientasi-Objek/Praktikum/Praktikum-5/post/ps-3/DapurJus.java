import java.util.*;

public class DapurJus {
    private DapurJus(){}

    public static void cekBahan(List<? extends Buah> daftarBahan){
        for(Buah b : daftarBahan){
            System.out.println(b.deskripsi());
        }
    }
    public static int hitungTotalManis(List<? extends Buah> daftarBahan){
        int total = 0;
        for(Buah b : daftarBahan){
            total += b.getTingkatManis();
        }
        return total;
    }
    public static void buatJusApelDefault(List<? super JusApel> daftarMinuman){
        JusApel jp1 = new JusApel("Jus Apel Original");
        JusApel jp2 = new JusApel("Jus Apel Madu");
        daftarMinuman.add(jp1);
        daftarMinuman.add(jp2);
    }
    public static void cetakRakUmum(List<?> rak){
        for(int i=0; i<rak.size(); i++){
            System.out.println(rak.get(i).toString());
        }
    }
}