class Main {
  public static void main(String[] args) {
    PrimComponent spherePrim = new PrimComposite("Sphere Object");
    PrimComponent boxPrim = new PrimComposite("Box Object");
    PrimComponent cylinderPrim = new PrimComposite("Cylinder Object");

    spherePrim.addComponent(new Sphere(3));
    boxPrim.addComponent(new Box(2, 3, 4));
    cylinderPrim.addComponent(new Cylinder(3, 4));

    PrimComponent sphereBoxPrim = new PrimComposite("Car - 4 Sphere & 1 Box");
    sphereBoxPrim.addComponent(spherePrim);
    sphereBoxPrim.addComponent(spherePrim);
    sphereBoxPrim.addComponent(spherePrim);
    sphereBoxPrim.addComponent(spherePrim);
    sphereBoxPrim.addComponent(boxPrim);

    spherePrim.print();
    System.out.println("------------------------------------");

    boxPrim.print();
    System.out.println("------------------------------------");

    cylinderPrim.print();
    System.out.println("------------------------------------");

    sphereBoxPrim.print();
  }
}