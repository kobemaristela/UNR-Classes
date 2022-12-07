public class BallsBlue extends Decoration{

    public BallsBlue (Tree tree) {
        this.myTree = tree;
        isStar = tree.isStar;
    }
    
    public String getDescription() {
        return myTree.getDescription() + " + Balls Blue";
    }

    public int cost() {
        return myTree.cost() + 2;
    }
}