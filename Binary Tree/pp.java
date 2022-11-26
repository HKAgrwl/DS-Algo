interface Foo{
    String name="Foo";
    void print();
}

class Bar extends Foo{
    String name = "Bar";
}

public void print(){
    System.out.println(name);
}

public static void main(String[] args) {
    Foo foo = new Bar();
    foo.print();
}