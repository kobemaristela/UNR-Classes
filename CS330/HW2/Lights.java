public class Lights extends Decoration{

    public Lights (Tree tree) {
        this.myTree = tree;
        isStar = tree.isStar;
    }
    
    public String getDescription() {
        return myTree.getDescription() + " + Lights";
    }

    public int cost() {
        return myTree.cost() + 5;
    }
}