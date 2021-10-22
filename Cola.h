
struct CompareAge {
    bool operator()(Dios & p1, Dios & p2) {
        return p1.getFieles() < p2.getFieles();
    }
};

class Cola{

    public:

    void imprimirCola(priority_queue<Dios, vector<Dios>, CompareAge> pColaPrueba)
    {
        while (!pColaPrueba.empty())
        {
            cout << pColaPrueba.top().getName() << endl;
            pColaPrueba.pop();
            }
        }
};
