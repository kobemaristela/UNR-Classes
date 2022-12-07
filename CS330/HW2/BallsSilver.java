public class BallsSilver extends Decoration{

    public BallsSilver (Tree tree) {
        this.myTree = tree;
        isStar = tree.isStar;
    }
    
    public String getDescription() {
        return myTree.getDescription() + " + Balls Silver";
    }

    public int cost() {
        return myTree.cost() + 3;
    }
}