#include "tabelas.h"

namespace base
{

	RegistroIncompativelException::RegistroIncompativelException(const Registro* reg)
		: registro(reg)
	{}

	Alunos::Alunos()
		: Tabela("alunos")
	{}

	Alunos::AlunoIter Alunos::search(const Aluno& aluno)
	{
		for(AlunoIter it = alunos.begin(); it != alunos.end(); it++)
		{
			if((*it).getMatricula() == aluno.getMatricula())
			{
				return it;
			}
		}
		return AlunoIter(0);
	}

	void Alunos::store(Registro* reg)
	{
		if( Aluno* aluno= dynamic_cast<Aluno*>(reg) )
			alunos.push_back(*aluno);
		else
			throw(RegistroIncompativelException(reg));
	}

	void Alunos::remove(Registro* reg)
	{
		if( Aluno* aluno = dynamic_cast<Aluno*>(reg) )
			alunos.erase(search(*aluno));
		else
			throw(RegistroIncompativelException(reg));
	}

	void Alunos::update(Registro* reg)
	{
		if( Aluno* aluno = dynamic_cast<Aluno*>(reg) )
		{
			AlunoIter it = search(*aluno);
			*it = *aluno;
		}
		else
			throw(RegistroIncompativelException(reg));
	}


}