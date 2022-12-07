public class Ruffles extends Decoration{

    public Ruffles (Tree tree) {
        this.myTree = tree;
        isStar = tree.isStar;
    }
    
    public String getDescription() {
        return myTree.getDescription() + " + Ruffles";
    }

    public int cost() {
        return myTree.cost() + 1;
    }
}