public class Ribbons extends Decoration{

    public Ribbons (Tree tree) {
        this.myTree = tree;
        isStar = tree.isStar;
    }
    
    public String getDescription() {
        return myTree.getDescription() + " + Ribbons";
    }

    public int cost() {
        return myTree.cost() + 2;
    }
}