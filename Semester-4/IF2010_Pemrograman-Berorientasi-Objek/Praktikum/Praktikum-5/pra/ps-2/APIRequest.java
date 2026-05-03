public class APIRequest<T> {
    // Berisi public class APIRequest<T> dengan spesifikasi:
    //
    // Memiliki atribut private String endpoint dan T payload (data yang dikirim).
    // Memiliki constructor untuk menginisialisasi kedua atribut tersebut.
    // Memiliki Generic Method bernama execute. Method ini menerima tipe generic baru <U> dengan parameter: int statusCode, String message, dan U responseData.
    // Method execute ini harus melakukan dua hal:
    //     Mencetak log ke layar: Executing Request to [endpoint] with payload: [payload]
    //     Mengembalikan sebuah objek APIResponse<U> yang baru dibuat berdasarkan parameter yang diterimanya.

    private String endpoint;
    private T payload;

    public APIRequest(String endpoint, T payload) {
        this.endpoint = endpoint;
        this.payload = payload;
    }

    public <U> APIResponse<U> execute(int statusCode, String message, U responseData) {
        System.out.println("Executing Request to " + this.endpoint + " with payload: " + this.payload);
        return new APIResponse<>(statusCode, message, responseData);
    }

}
