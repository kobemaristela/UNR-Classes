
public class DanceAdapter implements GuitarController{
    DanceController dance;

    public DanceAdapter(DanceController controller) {
        this.dance = controller;
    }

    public void pressFretButton(colors button) {
        dance.step(DanceController.direction.values()[button.ordinal()], null);
    }

    public void pressPick() {
        System.out.println("No mapping for command...");
    }

    public void pressTremelo(){
        System.out.println("No mapping for command...");
    }

}
