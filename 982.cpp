#include <iostream>
#include <vector>

int main() {
	int n, m;

	std::cin >> n >> m;

	std::vector<int> visited(n);

	for(unsigned i = 0; i < visited.size(); i++)
		visited[i] = i;

	for(int i = 0; i < m; i++) {
		int u, v;
		
		std::cin >> u >> v;
		
		u--; 
		v--;
		
		int color = visited[v];
		for(unsigned i = 0; i < visited.size(); i++) {
			if(visited[i] == color)
				visited[i] = visited[u];			
		}
	}

	bool isAllSame = true;

	for(unsigned i = 0; i < visited.size(); i++)
		isAllSame = isAllSame && (visited[i] == visited[0]);
	
	if(isAllSame) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
	return 0;
}