public class BurgerCommand implements Command {
    ShortOrderCook myCook;

    public BurgerCommand(ShortOrderCook cook){
        this.myCook = cook;
    }
    public void orderUp(){
        myCook.makeBurger();
    }

}