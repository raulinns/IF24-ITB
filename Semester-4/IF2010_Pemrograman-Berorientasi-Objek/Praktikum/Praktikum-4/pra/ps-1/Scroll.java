public abstract class Scroll {
    protected String content;
    protected String type;

    public Scroll(String content) {
        this.content = content;
        this.type = "";
    }

    public String getContent() {
        return content;
    }

    public abstract String process();

    @Override
    public String toString() {
        return "[" + this.type + "] " + this.content;
    }
}
