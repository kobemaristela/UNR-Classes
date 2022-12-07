public class LEDs extends Decoration{

    public LEDs (Tree tree) {
        this.myTree = tree;
        isStar = tree.isStar;
    }
    
    public String getDescription() {
        return myTree.getDescription() + " + LEDs";
    }

    public int cost() {
        return myTree.cost() + 10;
    }
}