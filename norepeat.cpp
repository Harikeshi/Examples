int main()
{
	string s = "abbbaa"; // -> ababab

	map<char, int> m;
	for (auto c : s)
	{
		if (!m.contains(c))
		{
			m.insert({ c, 0 });
		}
		m[c]++;
	}

	list<char> res;
	while (!m.empty())
	{
		for (auto i = m.begin(); i != m.end() && !m.empty();)
		{
			if ((i)->second != 0)
			{
				res.push_back(i->first);
				--(i->second);
			}
			if (m.size() == 1)
			{
				for (auto j = ++(res.begin()), t = res.begin();
					j != res.end() && i->second != 0; ++t)
				{
					if (*j != i->first && *t != i->first)
					{
						res.insert(j++, i->first);
						--(i->second);
						++t;
					}
					else ++j;
				}
				for (; i->second!=0; --i->second)
				{
					res.push_back(i->first);
				}
			}
			if (i->second == 0) m.erase(i++);
			else i++;
		}
	}
	
	char t = *(++res.begin());
	bool ok = 1;
	for (auto x : res)
	{
		if (t == x) ok = 0;
		t = x;
	}
	if (ok) for (auto x : res) cout << x;
	else cout << "Not ok!";
}
