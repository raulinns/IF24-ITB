public class CipherScroll extends Scroll {
    private int shift;

    public CipherScroll(String content, int shift) {
        super(content);
        this.type = "CIPHER";
        this.shift = shift;
    }

    private String cipher(int s) {
        char[] chars = this.content.toCharArray();
        char[] result = new char[chars.length];
        for (int i = 0; i < chars.length; i++) {
            char c = chars[i];
            if (Character.isLetter(c)) {
                char base = Character.isUpperCase(c) ? 'A' : 'a';
                result[i] = (char) (((c - base + s % 26 + 26) % 26) + base);
            } else {
                result[i] = c;
            }
        }
        return new String(result);
    }

    @Override
    public String process() {
        return cipher(this.shift);
    }

    public String decode() {
        return cipher(-this.shift);
    }
}
