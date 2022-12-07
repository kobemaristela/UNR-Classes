
public class GuitarAdapter implements DanceController{
    GuitarController guitar;

    public GuitarAdapter(GuitarController controller) {
        this.guitar = controller;
    }

    public void step(direction dir1, direction dir2) {
         // Press Button
        if(dir2 == null){
            guitar.pressFretButton(GuitarController.colors.values()[dir1.ordinal()]);
            return;
        }

        // Inputs - FORWARD & BACK --> pressPick()
        if(dir1 == direction.FORWARD && dir2 == direction.BACK){
            guitar.pressPick();
        }

        // Inputs - RIGHT & LEFT --> pressPick()
        if(dir1 == direction.RIGHT && dir2 == direction.LEFT){
            guitar.pressTremelo();
        }

    }

}
