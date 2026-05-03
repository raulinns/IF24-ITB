public class APIResponse<U> {
    private int statusCode;
    private String message;
    U data;
    
    public APIResponse(int status, String msg, U data) {
        this.statusCode = status;
        this.message = msg;
        this.data = data;
    }

    public void printResponse() {
        String typeName = this.data.getClass().getSimpleName();
        System.out.println("Response " + statusCode + " - " + message + " | Data: " + data + " (Type: " + typeName+ ")"
);
    }
}
