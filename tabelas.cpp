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

	Aluno* Alunos::getAluno(unsigned int matricula)
	{
		for(AlunoIter it = alunos.begin(); it != alunos.end(); it++)
		{
			if((*it).getMatricula() == matricula)
				return &*it;
		}
		return 0;
	}

	Alunos::AlunoIter Alunos::begin() const
	{
		return alunos.begin();
	}

	Alunos::AlunoIter Alunos::end() const
	{
		return alunos.end();
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
			if((*it).getCodigoRegistro() == curso.getCodigoRegistro())
				return it;
		}
		return CursoIter(0);
	}

	Curso* Cursos::getCurso(const std::string& codigo)
	{
		for(CursoIter it = cursos.begin(); it != cursos.end(); it++)
		{
			if((*it).getCodigo() == codigo)
				return &*it;
		}
		return 0;
	}

	Turmas::Turmas()
		: Tabela("turmas"), turmas()
	{}

	void Turmas::store(Registro* reg)
	{
		if( Turma* turma = dynamic_cast<Turma*>(reg) )
		{
			if(reg->getCodigoRegistro() == reg->NAO_REGISTRADO)
			{
				codigo++;
				turma->setCodigoRegistro(codigo);
				turmas.push_back(*turma);
			}
		}
		else
			throw(RegistroIncompativelException(reg));
	}

	void Turmas::remove(Registro* reg)
	{
		if( Turma* turma = dynamic_cast<Turma*>(reg) )
		{
			if(reg->getCodigoRegistro() != reg->NAO_REGISTRADO)
			{
				turmas.erase(search(*turma));
				reg->setCodigoRegistro(reg->NAO_REGISTRADO);
			}
		}
		else
			throw(RegistroIncompativelException(reg));
	}

	void Turmas::update(Registro* reg)
	{
		if( Turma* turma = dynamic_cast<Turma*>(reg) )
		{
			if(reg->getCodigoRegistro() != reg->NAO_REGISTRADO)
			{
				TurmaIter it = search(*turma);
				if(it.node_ptr != 0)
					*it = *turma;
			}
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

	Turma* Turmas::getTurma(const std::string& cod_curso, const std::string& cod_turma)
	{
		Turma* t = 0;
		for(list<Turma>::iterator it = turmas.begin(); it != turmas.end(); it++)
		{
			if((*it).getCurso().getCodigo() == cod_curso && (*it).getCodigo() == cod_turma)
			{
				t = &(*it);
				break;
			}
		}
		return t;
	}

	Professores::Professores()
		: Tabela("professores"), professores()
	{}

	Professores::ProfIter Professores::begin() const
	{
		return professores.begin();
	}

	Professores::ProfIter Professores::end() const
	{
		return professores.end();
	}

	Professor* Professores::getProfessor(const std::string& siape)
	{
		for(ProfIter it = professores.begin(); it != professores.end(); it++)
		{
			if((*it).getSiape() == siape)
				return &*it;
		}
		return 0;
	}

	void Professores::store(Registro* reg)
	{
		if( Professor* prof = dynamic_cast<Professor*>(reg) )
		{
			if(reg->getCodigoRegistro() == reg->NAO_REGISTRADO)
			{
				codigo++;
				prof->setCodigoRegistro(codigo);
				professores.push_back(*prof);
			}
		}
		else
			throw(RegistroIncompativelException(reg));
	}

	void Professores::remove(Registro* reg)
	{
		if( Professor* prof = dynamic_cast<Professor*>(reg) )
		{
			if(reg->getCodigoRegistro() != reg->NAO_REGISTRADO)
			{
				professores.erase(search(*prof));
				reg->setCodigoRegistro(reg->NAO_REGISTRADO);
			}
		}
		else
			throw(RegistroIncompativelException(reg));
	}

	void Professores::update(Registro* reg)
	{
		if( Professor* prof = dynamic_cast<Professor*>(reg) )
		{
			if(reg->getCodigoRegistro() != reg->NAO_REGISTRADO)
			{
				ProfIter it = search(*prof);
				if(it.node_ptr != 0)
					*it = *prof;
			}
		}
		else
			throw(RegistroIncompativelException(reg));
	}

	Professores::ProfIter Professores::search(const Professor& prof)
	{
		if(prof.getCodigoRegistro() == -1)
			return ProfIter(0);

		for(ProfIter it = professores.begin(); it != professores.end(); it++)
		{
			if((*it).getCodigoRegistro() == prof.getCodigoRegistro())
				return it;
		}
		return ProfIter(0);
	}

#define DSC Disciplinas
#define DSC_CAST dynamic_cast<Disciplina*>

	DSC::Disciplinas()
		: Tabela("disciplinas")
	{}

	void DSC::store(Registro *reg)
	{
		if(Disciplina* d = DSC_CAST(reg))
		{
			if(reg->getCodigoRegistro() == reg->NAO_REGISTRADO)
			{
				reg->setCodigoRegistro(++codigo);
				disciplinas.push_back(*d);
			}
		}
		else
			throw(RegistroIncompativelException(reg));
	}

	void DSC::remove(Registro *reg)
	{
		if(Disciplina* d = DSC_CAST(reg))
		{
			if(reg->getCodigoRegistro() != reg->NAO_REGISTRADO)
			{
				disciplinas.erase(search(*d));
				reg->setCodigoRegistro(reg->NAO_REGISTRADO);
			}
		}
		else
			throw(RegistroIncompativelException(reg));
	}

	void DSC::update(Registro* reg)
	{
		if(Disciplina* d = DSC_CAST(reg))
		{
			if(reg->getCodigoRegistro() != reg->NAO_REGISTRADO)
			{
				DisciplinaIter it = search(*d);
				Disciplina& me = *it;
				me.setCarga(d->getCarga());
				me.setCodigo(d->getCodigo());
				me.setCurso(&d->getCurso());
				me.setNome(d->getNome());
				me.setRequisitos(d->getRequisitosBeginIter(), d->getRequisitosEndIter());
			}
		}
		else
			throw(RegistroIncompativelException(reg));
	}

	Disciplina* DSC::getDisciplina(const std::string& cod_disc, const std::string& cod_curso)
	{
		for(DisciplinaIter it = disciplinas.begin(); it != disciplinas.end(); it++)
		{
			if((*it).getCodigo() == cod_disc && (*it).getCurso().getCodigo() == cod_curso)
				return &(*it);
		}
		return 0;
	}

	DSC::DisciplinaIter DSC::search(const Disciplina& disc)
	{
		for(DisciplinaIter it = disciplinas.begin(); it != disciplinas.end(); it++)
		{
			if((*it).getCodigoRegistro() == disc.getCodigoRegistro())
				return it;
		}

		return DisciplinaIter(0);
	}

	Notas::Notas()
		: notas(), Tabela("notas")
	{}
#define NOTA_CAST dynamic_cast<Nota*> 
	void Notas::store(Registro* reg)
	{
		if(reg->getCodigoRegistro() == reg->NAO_REGISTRADO)
		{
			if(Nota* n = NOTA_CAST(reg))
			{
				reg->setCodigoRegistro(codigo++);
				notas.push_back(*n);
			}
		}
		else
			throw RegistroIncompativelException(reg);
	}
	void Notas::remove(Registro* reg)
	{
		if(Nota* n = NOTA_CAST(reg))
		{
			if(reg->getCodigoRegistro() != reg->NAO_REGISTRADO)
			{
				notas.erase(search(*n));
				reg->setCodigoRegistro(reg->NAO_REGISTRADO);
			}
		}
		else
			throw RegistroIncompativelException(reg);
	}
	void Notas::update(Registro* reg)
	{
		if(Nota* n = NOTA_CAST(reg))
		{
			if(reg->getCodigoRegistro() != reg->NAO_REGISTRADO)
			{
				NotaIter it = search(*n);
				if(it.node_ptr != 0)
				{
					(*it).setAluno(n->getAluno());
					(*it).setNota(n->getNota());
					(*it).setTurma(n->getTurma());
				}
			}
		}
		else
			throw RegistroIncompativelException(reg);
	}
	
	Notas::NotaIter Notas::search(const Nota& nota)
	{
		for(NotaIter it = notas.begin(); it != notas.end(); it++)
		{
			if((*it).getCodigoRegistro() == nota.getCodigoRegistro())
				return it;
		}
		return NotaIter(0);
	}

	Nota* Notas::getNota(const std::string& codTurma, unsigned int mat)
	{
		for(NotaIter it = notas.begin(); it != notas.end(); it++)
		{
			if((*it).getTurma()->getCodigo() == codTurma && 
				(*it).getAluno()->getMatricula() == mat)
				return &(*it);
		}
	}
}