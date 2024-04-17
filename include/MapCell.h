


class MapCell {
public:
    MapCell(char symbolP) : symbol(symbolP) {};
    char getSymbol() const { return symbol; }
protected:
    char symbol;
};