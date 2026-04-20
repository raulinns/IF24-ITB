public class PlainScroll extends Scroll {
    public PlainScroll(String content) {
        super(content);
        this.type = "PLAIN";
    }

    @Override
    public String process() {
        String plainString = this.content;
        String trimmed = plainString.trim().replaceAll("\\s+", " ");
        String[] words = trimmed.split(" ");

        StringBuilder result = new StringBuilder();
        for (int i = 0; i < words.length; i++) {
            if (words[i].length() > 0) {
                result.append(Character.toUpperCase(words[i].charAt(0)))
                        .append(words[i].substring(1).toLowerCase());
                if (i < words.length - 1) result.append(" ");
            }
        }

        return result.toString();
    }
}
