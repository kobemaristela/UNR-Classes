public class ShakeCommand implements Command{
    ShortOrderCook myCook;

    public ShakeCommand(ShortOrderCook cook){
        this.myCook = cook;
    }
    public void orderUp(){
        myCook.makeShake();
    }
  
}
