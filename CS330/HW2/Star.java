public class Star extends Decoration{

    public Star (Tree tree) {
        this.myTree = tree;

        if (myTree.isStar != null && myTree.isStar) {
            System.out.println("Warning: Christmas tree already has a star!!!");
        }

        isStar = true;
    }
    
    public String getDescription() {
        if (myTree.isStar != null && myTree.isStar) {
            return myTree.getDescription();
        }
        
        return myTree.getDescription() + " + Star";
    }

    public int cost() {
        if (myTree.isStar != null && myTree.isStar) {
            return myTree.cost();
        }
    
        return myTree.cost() + 4;
    }
}
