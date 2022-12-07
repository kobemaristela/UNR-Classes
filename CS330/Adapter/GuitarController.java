public interface GuitarController {
    public static enum colors {GREEN,RED,YELLOW,BLUE,ORANGE}
    public void pressFretButton(colors button);
    public void pressPick();
    public void pressTremelo();
}