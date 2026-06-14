public class DigitalClock {
    private int hour;
    private int minute;
    private int second;
    private TimeMode mode;

    public DigitalClock(int hour, int minute, int second) {
        if (hour < 0 || hour > 23) {
            throw new IllegalArgumentException("Invalid hour");
        }
        if (minute < 0 || minute > 59) {
            throw new IllegalArgumentException("Invalid minute");
        }
        if (second < 0 || second > 59) {
            throw new IllegalArgumentException("Invalid second");
        }

        this.hour = hour;
        this.minute = minute;
        this.second = second;
        this.mode = TimeMode.NORMAL;

        assert isValidState() : "Invalid clock state after constructor";
    }

    public void tick() {
        addOneSecond();
        assert isValidState() : "Invalid clock state after tick";
    }

    public void addSeconds(int seconds) {
        if (seconds < 0) {
            throw new IllegalArgumentException("seconds must be non-negative");
        }

        for (int i = 0; i < seconds; i++) {
            addOneSecond();
        }

        assert isValidState() : "Invalid clock state after addSeconds";
    }

    public void setMode(String modeName) {
        if (modeName == null) {
            throw new IllegalArgumentException("modeName cannot be null");
        }

        try {
            this.mode = TimeMode.valueOf(modeName);
        } catch (IllegalArgumentException e) {
            throw new IllegalArgumentException("Invalid mode");
        }

        assert this.mode != null : "Mode should never be null";
    }

    public String format() {
        switch (mode) {
            case NORMAL:
                return String.format("%02d:%02d:%02d", hour, minute, second);
            case COMPACT:
                return String.format("%02d%02d%02d", hour, minute, second);
            default:
                assert false;
                return "";
        }
    }

    private void addOneSecond() {
        assert isValidState() : "Precondition failed before addOneSecond";

        second++;

        if (second == 60) {
            second = 0;
            minute++;
        }

        if (minute == 60) {
            minute = 0;
            hour++;
        }

        if (hour == 24) {
            hour = 0;
        }

        assert isValidState() : "Postcondition failed after addOneSecond";
    }

    private boolean isValidState() {
        return hour >= 0 && hour <= 23
                && minute >= 0 && minute <= 59
                && second >= 0 && second <= 59;
    }
}
