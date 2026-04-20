import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int N = input.nextInt();
        input.nextLine();

        Courier[] kurir = new Courier[N];
        String[] barang = new String[N];
        int y = -999999;
        double x = 0;

        for(int i = 0; i < N ; i++){
            String jenis = input.next();
            String nama = input.next();
            int speed = input.nextInt();
            String item = input.next();

            if(jenis.equals("B")){
                kurir[i] = new BikeCourier(nama, speed);
            } else {
                kurir[i] = new CarCourier(nama, speed);
            }
            System.out.println(kurir[i].toString());

            barang[i] = item;
            System.out.println(kurir[i].deliver(barang[i]));
            
            if(y < speed){
                y = speed;
            }
            x += speed;
        }

        if(N == 0){
            System.out.println("Average speed: 0.00");
        } else{
            System.out.printf("Average speed: %.2f\n", x / N);
        }

        boolean fast = y > 40;
        if(fast){
            System.out.println("Fast? true");
        } else {
            System.out.println("Fast? false");
        }

        input.close();
    }
}