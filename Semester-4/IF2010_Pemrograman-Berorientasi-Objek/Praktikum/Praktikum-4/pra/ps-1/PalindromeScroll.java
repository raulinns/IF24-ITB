public class PalindromeScroll extends Scroll {
    public PalindromeScroll(String content) {
        super(content);
        this.type = "PALINDROME";
    }

    @Override
    public String process() {
        return new StringBuilder(content).reverse().toString();
    }

    public boolean isPalindrome() {
        String clean = content.replaceAll("\\s+", "").toLowerCase();
        String reversed = new StringBuilder(clean).reverse().toString();
        return clean.equals(reversed);
    }

}
