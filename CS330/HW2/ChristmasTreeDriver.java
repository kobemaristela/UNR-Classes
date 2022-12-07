
public class ChristmasTreeDriver {
    public static void main(String args[]){

        // Blue Spruce + extra star
        Tree spruce = new BlueSpruce();
        spruce = new Star(spruce);
        spruce = new Ruffles(spruce);
        spruce = new Star(spruce);
        spruce = new Ruffles(spruce);

        System.out.println(spruce.getDescription() + " = $" + spruce.cost() + "\n");

        
        // Balsam Fir + extra star
        Tree balsam = new BalsamFir();
        balsam = new Star(balsam);
        balsam = new Ruffles(balsam);
        balsam = new BallsRed(balsam);
        balsam = new Star(balsam);
        balsam = new BallsBlue(balsam);

        System.out.println(balsam.getDescription() + " = $" + balsam.cost() + "\n");


        // Douglas Fir
        Tree douglas = new DouglasFir();
        douglas = new Star(douglas);
        douglas = new BallsSilver(douglas);
        douglas = new Ribbons(douglas);
        douglas = new Lights(douglas);

        System.out.println(douglas.getDescription() + " = $" + douglas.cost() + "\n");


        // Fraser Fir
        Tree fraser = new FraserFir();
        fraser = new Star(fraser);
        fraser = new LEDs(fraser);
        fraser = new LEDs(fraser);
        fraser = new LEDs(fraser);

        System.out.println(fraser.getDescription() + " = $" + fraser.cost() + "\n");
        
    }
}