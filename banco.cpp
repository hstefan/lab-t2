#include "banco.h"

namespace bd
{
	void Banco::registerTable(Tabela* table)
	{
		tabelas.push_back(table);
	}

	Banco::TabelaIter Banco::searchTable(const std::string& name)
	{
		for(ds::list<Tabela*>::iterator it = tabelas.begin(); it != tabelas.end(); it++)
		{
			if((*it)->table_name() == name) 
			{
				return it;
				break;
			}
		}
		return TabelaIter(0);
	}

	void Banco::deleteTable(const std::string& name)
	{
		tabelas.erase(searchTable(name));
	}

	void Banco::save(const std::string& table, Registro* reg)
	{
		TabelaIter ti = searchTable(table);
		(*ti)->store(reg);
	}

	void Banco::sync(const std::string& table, Registro* reg)
	{
		TabelaIter ti = searchTable(table);
		(*ti)->update(reg);
	}

	void Banco::erase(const std::string& table, Registro* reg)
	{
		TabelaIter ti = searchTable(table);
		(*ti)->remove(reg);
	}

	Tabela::Tabela(const std::string& table_name)
		: name(table_name)
	{}

	const std::string& Tabela::table_name() const
	{
		return name;
	}
}