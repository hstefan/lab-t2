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
			if(it.node_ptr != 0)
				*it = *aluno;
		}
		else
			throw(RegistroIncompativelException(reg));
	}

	Cursos::Cursos()
		: Tabela("cursos"), cursos()
	{}

	void Cursos::store(Registro* reg)
	{
		if( Curso* curso = dynamic_cast<Curso*>(reg) )
			cursos.push_back(*curso);
		else
			throw(RegistroIncompativelException(reg));
	}

	void Cursos::remove(Registro* reg)
	{
		if( Curso* curso = dynamic_cast<Curso*>(reg) )
			cursos.erase(search(*curso));
		else
			throw(RegistroIncompativelException(reg));
	}

	void Cursos::update(Registro* reg)
	{
		if( Curso* curso = dynamic_cast<Curso*>(reg) )
		{
			CursoIter it = search(*curso);
			*it = *curso;
		}
		else
			throw(RegistroIncompativelException(reg));
	}

	Cursos::CursoIter Cursos::search(const Curso& curso)
	{
		for(CursoIter it = cursos.begin(); it != cursos.end(); it++)
		{
			if((*it).getCodigo() == curso.getCodigo())
				return it;
		}
		return CursoIter(0);
	}

	Turmas::Turmas()
		: Tabela("turmas"), turmas()
	{}

	void Turmas::store(Registro* reg)
	{
		if( Turma* turma = dynamic_cast<Turma*>(reg) )
		{
			codigo++;
			turma->setCodigoRegistro(codigo);
			turmas.push_back(*turma);
		}
		else
			throw(RegistroIncompativelException(reg));
	}

	void Turmas::remove(Registro* reg)
	{
		if( Turma* turma = dynamic_cast<Turma*>(reg) )
			turmas.erase(search(*turma));
		else
			throw(RegistroIncompativelException(reg));
	}

	void Turmas::update(Registro* reg)
	{
		if( Turma* turma = dynamic_cast<Turma*>(reg) )
		{
			TurmaIter it = search(*turma);
			*it = *turma;
		}
		else
			throw(RegistroIncompativelException(reg));
	}

	Turmas::TurmaIter Turmas::search(const Turma& turma)
	{
		if(turma.getCodigoRegistro() == -1)
			return TurmaIter(0);

		for(TurmaIter it = turmas.begin(); it != turmas.end(); it++)
		{
			if((*it).getCodigoRegistro() == turma.getCodigoRegistro())
				return it;
		}
		return TurmaIter(0);
	}

}