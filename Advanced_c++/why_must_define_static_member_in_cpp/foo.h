class Foo {
    int normalVariable;
    static int staticVariable;

    public:
        Foo();
        Foo(const Foo&);

        void setNormal(int);
        int getNormal();

        void setStatic(int);
        int getStatic();
};
