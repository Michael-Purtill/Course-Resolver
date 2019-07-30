#include <iostream>
#include <vector>

using namespace std;

class CourseNode
{
	private:
		vector<string> cons;
		string name;
	public:
		CourseNode(string c, string e, string m, string p, string en, string n)
		{
			cons.push_back(c);
			cons.push_back(e);
			cons.push_back(m);
			cons.push_back(p);
			cons.push_back(en);
			name = n;
		}

		vector<string> get_cons()
		{
			return cons;
		}
		
		string get_name()
		{
			return name;
		}
};

void resolver(vector<vector<CourseNode>> &nc, vector<CourseNode> &g);
bool contest(vector<CourseNode> &x, CourseNode& y);
int blacount(CourseNode &in);

int main()
{
	CourseNode cs(" ", "econ", "math", "phy", "eng", "cs");
	CourseNode econ("cs", " ", " ", " ", " ", "econ");
	CourseNode math("cs", " ", " ", " ", "eng", "math");
	CourseNode phy("cs", " ", " ", " ", " ", "phy");
	CourseNode eng("cs", " ", "math", " ", " ", "eng");

	vector<CourseNode> graph;

	graph.push_back(cs);
	graph.push_back(econ);
	graph.push_back(math);
	graph.push_back(phy);
	graph.push_back(eng);
	
	vector<vector<CourseNode>> nocons;

	while (graph.size() > 0)
	{	
		resolver(nocons, graph);
	}
	
	for (int i = 0; i < nocons.size(); i++)
	{
		cout << i + 1 << ") "; 
		for (int j = 0; j < nocons[i].size(); j++)
		{	
			cout << nocons[i][j].get_name() << " ";
		}
		cout << endl;
	}

}

void resolver(vector<vector<CourseNode>> &nc, vector<CourseNode> &g)
{
	//i'm gonna try a greedy algorithm which will
	//take ones with least connections.
	vector<CourseNode> temp;
	int max{0};
	int maxindex{0};
	
	for (int i = 0; i < g.size(); i++)
	{
		if (blacount(g[i]) > max)
		{
			max = blacount(g[i]);
			maxindex = i;
		}
	}

	temp.push_back(g[maxindex]);
	g.erase(g.begin() + maxindex);
	for (int i = 0; i < g.size(); i++)
	{
		if (contest(temp, g[i]) == false)
		{	
			temp.push_back(g[i]);
			g.erase(g.begin() + i);
			i = 0;
		}
	}

	nc.push_back(temp);
}

bool contest(vector<CourseNode> &x, CourseNode& y)
{
	for (int i = 0; i < x.size(); i++)
	{
		for (int j = 0; j < y.get_cons().size(); j++)
		{
			if (y.get_cons()[j] == x[i].get_name())
				return true;
		}
	}

	return false;
}

int blacount(CourseNode &in)
{
	int counter{0};
	for (int i = 0; i < in.get_cons().size(); i++)
	{
		
		if (in.get_cons()[i] == " ")
			counter++;
	}
	return counter;
}

