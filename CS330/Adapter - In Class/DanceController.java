public interface DanceController {
    public static enum direction {FORWARD,LEFT,RIGHT, BACK, MIDDLE}
    public void step(direction dir1, direction dir2);
}
