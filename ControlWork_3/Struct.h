enum GoodsName
{
	Laptops = 1, Cooler, Cpu, AllinOnePC, Ram, Ssd, Videocard
};

struct Goods
{
	int code;
	char name[250];
	int retailPrice;
	int wholesalePrice;
};

struct Basket
{	
	char name[250];
	long cost;
};

struct AllBasket
{
	char name[250];
	long cost;
};