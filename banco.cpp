#include "banco.h"

namespace bd
{
	void Banco::registerTable(Tabela* table)
	{
		tabelas.push_back(table);
	}

	void Banco::deleteTable(const std::string& name)
	{
		for(ds::list<Tabela*>::iterator it = tabelas.begin(); it != tabelas.end(); it++)
		{
			if((*it)->table_name() == name) 
			{
				tabelas.erase(it);
				break;
			}
		}
	}

	void Banco::save(const std::string& table, Registro* reg)
	{
		for(ds::list<Tabela*>::iterator it = tabelas.begin(); it != tabelas.end(); it++)
		{
			if((*it)->table_name() == table) 
			{
				(*it)->store(reg);
				break;
			}
		}
	}

	void Banco::sync(const std::string& table, Registro* reg)
	{
		for(ds::list<Tabela*>::iterator it = tabelas.begin(); it != tabelas.end(); it++)
		{
			if((*it)->table_name() == table) 
			{
				(*it)->update(reg);
				break;
			}
		}
	}

	void Banco::erase(const std::string& table, Registro* reg)
	{
		tabelas[table]->remove(reg);
	}

	Tabela::Tabela(const std::string& table_name)
		: name(table_name)
	{}

	const std::string& Tabela::table_name() const
	{
		return name;
	}
}