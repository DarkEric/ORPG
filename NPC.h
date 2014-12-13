#ifndef NPC_H
#define NPC_H
class NPC
{
	public:
		NPC();
		virtual void Dialog();
		void Set_x(int n);
		int Get_x();
		void Set_y(int n);
		int Get_y();
		~NPC();
private:
	int x;
	int y;
};

#endif
