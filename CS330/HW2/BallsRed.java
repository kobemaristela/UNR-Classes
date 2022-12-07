public class BallsRed extends Decoration{

    public BallsRed (Tree tree) {
        this.myTree = tree;
        isStar = tree.isStar;
    }
    
    public String getDescription() {
        return myTree.getDescription() + " + Balls Red";
    }

    public int cost() {
        return myTree.cost() + 1;
    }
}