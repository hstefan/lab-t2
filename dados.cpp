#include "dados.h"
#include "banco.h"

namespace base
{
	using bd::Banco;
	Aluno::Aluno(const Curso* curso, unsigned int matricula, const std::string& nome)
		: curso(curso), matricula(matricula), nome(nome), Registro("alunos") 
	{}

	Aluno& Aluno::operator=(const Aluno& aluno)
	{
		curso = aluno.curso;
		matricula = aluno.getMatricula();
		nome = aluno.getNome();
		return *this;
	}

	void Aluno::save()
	{
		Banco::getInstance().save(nome_tabela, this);
	}

	void Aluno::erase()
	{
		Banco::getInstance().erase(nome_tabela, this);
	}

	void Aluno::sync()
	{
		Banco::getInstance().sync(nome_tabela, this);
	}

	const Curso& Aluno::getCurso() const
	{ 
		return *curso; 
	}

	unsigned int Aluno::getMatricula() const
	{ 
		return matricula; 
	}

	const std::string& Aluno::getNome() const
	{ 
		return nome; 
	}

	void Aluno::setCurso(const Curso* curso)
	{
		this->curso = curso;
	}

	void Aluno::setMatricula(unsigned int matricula)
	{
		this->matricula = matricula;
	}

	void Aluno::setNome(const std::string& nome)
	{
		this->nome = nome;
	}

	Professor::Professor(const std::string& siape, const std::string& nome, 
		const std::string& area, const std::string& titulacao)
		: siape(siape), nome(nome), area(area), titulacao(titulacao), Registro("professores")
	{}

	Professor& Professor::operator=(const Professor& professor)
	{
		setSiape(professor.getSiape());
		setNome(professor.getNome());
		setArea(professor.getArea());
		setTitulacao(professor.getTitulacao());
		return *this;
	}

	void Professor::save()
	{
		Banco::getInstance().save(nome_tabela, this);
	}

	void Professor::erase()
	{
		Banco::getInstance().erase(nome_tabela, this);
	}

	void Professor::sync()
	{
		Banco::getInstance().sync(nome_tabela, this);
	}

	void Professor::setSiape(const std::string& siape)
	{
		this->siape = siape;
	}

	void Professor::setNome(const std::string& nome)
	{
		this->nome = nome;
	}

	void Professor::setArea(const std::string& area)
	{
		this->area = area;
	}

	void Professor::setTitulacao(const std::string& titulacao)
	{
		this->titulacao = titulacao;
	}

	const std::string& Professor::getSiape() const
	{
		return siape;
	}

	const std::string& Professor::getNome() const
	{
		return nome;
	}

	const std::string& Professor::getArea() const
	{
		return area;
	}

	const std::string& Professor::getTitulacao() const
	{
		return titulacao;
	}

	Disciplina::Disciplina(const std::string& codigo, Curso* curso, const std::string& nome, 
			unsigned int carga, ds::list<Disciplina>& requisitos)
		: codigo(codigo), curso(curso), nome(nome), carga(carga), requisitos(), Registro("disciplinas")
	{
		for(ds::list<Disciplina>::iterator it = requisitos.begin(); it != requisitos.end(); it++)
		{
			this->requisitos.push_back(&*it);
		}
	}
	
	Disciplina& Disciplina::operator=(const Disciplina& disciplina)
	{
		setCodigo(disciplina.getCodigo());
		setCurso(&disciplina.getCurso());
		setNome(disciplina.getNome());
		setCarga(disciplina.getCarga());
		setRequisitos(disciplina.getRequisitosBeginIter(), disciplina.getRequisitosEndIter());
		return *this;
	}

	void Disciplina::save()
	{
		Banco::getInstance().save(nome_tabela, this);
	}

	void Disciplina::erase()
	{
		Banco::getInstance().erase(nome_tabela, this);
	}

	void Disciplina::sync()
	{
		Banco::getInstance().sync(nome_tabela, this);
	}

	void Disciplina::setCodigo(const std::string& codigo)
	{
		this->codigo = codigo;
	}

	void Disciplina::setCurso(const Curso* curso)
	{
		this->curso = curso;
	}

	void Disciplina::setNome(const std::string& nome)
	{
		this->nome = nome;
	}

	void Disciplina::setCarga(unsigned int carga)
	{
		this->carga = carga;
	}

	const std::string& Disciplina::getCodigo() const
	{
		return codigo;
	}

	const Curso& Disciplina::getCurso() const
	{
		return *curso;
	}

	const std::string& Disciplina::getNome() const
	{
		return nome;
	}

	unsigned int Disciplina::getCarga() const
	{
		return carga;
	}

	Disciplina::DiscIterator Disciplina::getRequisitosBeginIter() const
	{
		return requisitos.begin();
	}

	Disciplina::DiscIterator Disciplina::getRequisitosEndIter() const
	{
		return requisitos.end();
	}

	void Disciplina::adcionaRequisito(const Disciplina* disciplina)
	{
		requisitos.push_back(disciplina);
	}

	void Disciplina::removeRequisito(const Disciplina* disciplina)
	{
		for(DiscIterator it = requisitos.begin(); it != requisitos.end(); it++)
		{
			if(*it = disciplina)
			{
				removeRequisito(it);
				break;
			}
		}
	}

	void Disciplina::removeRequisito(DiscIterator disciplina)
	{
		requisitos.erase(disciplina);
	}

	Turma::Turma(const Curso* curso, const std::string& cod, ds::list<Aluno>& alunos, ds::list<Professor>& professores)
		: alunos(), professores(), curso(curso), Registro("turmas"), cod_turma(cod)
	{
		for(ds::list<Aluno>::iterator it = alunos.begin(); it != alunos.end(); it++)
			this->alunos.push_back(&(*it));
		for(ds::list<Professor>::iterator it = professores.begin(); it != professores.end(); it++)
			this->professores.push_back(&(*it));
	}

	Turma& Turma::operator=(const Turma& turma)
	{
		setCurso(&turma.getCurso());
		setAlunos(turma.getAlunosBegin(), turma.getAlunosEnd());
		setProfessores(turma.getProfessoresBegin(), turma.getProfessoresEnd());
		setCodigoRegistro(turma.getCodigoRegistro());
		setCodigo(turma.getCodigo());
		return *this;
	}

	std::string Turma::getCodigo() const
	{
		return cod_turma;
	}

	Turma::AlunosIter Turma::getAlunosBegin() const
	{
		return alunos.begin();
	}

	Turma::AlunosIter Turma::getAlunosEnd() const
	{
		return alunos.end();
	}

	Turma::ProfessoresIter Turma::getProfessoresBegin() const
	{
		return professores.begin();
	}

	Turma::ProfessoresIter Turma::getProfessoresEnd() const
	{
		return professores.end();
	}

	void Turma::setCodigo(const std::string& cod)
	{
		cod_turma = cod;
	}

	const Curso& Turma::getCurso() const
	{
		return *curso;
	}

	void Turma::setCurso(const Curso* curso)
	{
		this->curso = curso;
	}

	void Turma::adcionaAluno(Aluno* aluno)
	{
		alunos.push_back(aluno);
	}

	void Turma::adcionaProfessor(Professor* professor)
	{
		professores.push_back(professor);
	}

	void Turma::removerAluno(AlunosIter aluno)
	{
		alunos.erase(aluno);
	}

	void Turma::removerProfessor(ProfessoresIter professor)
	{
		professores.erase(professor);
	}

	void Turma::save()
	{
		Banco::getInstance().save(nome_tabela, this);
	}

	void Turma::erase()
	{
		Banco::getInstance().erase(nome_tabela, this);
	}

	void Turma::sync()
	{
		Banco::getInstance().sync(nome_tabela, this);
	}

	Curso::Curso(const std::string& codigo, const std::string& nome, ds::list<Turma>& turmas)
		: codigo(codigo), nome(nome), turmas(), Registro("cursos")
	{
		for(ds::list<Turma>::iterator it = turmas.begin(); it != turmas.end(); it++)
			this->turmas.push_back(&(*it));
	}

	Curso& Curso::operator=(const Curso& curso)
	{
		codigo = curso.getCodigo();
		nome = curso.getNome();
		turmas.clear();
		for(ds::list<Turma*>::iterator it = curso.getTurmasBegin(); it != turmas.end(); it++)
			this->turmas.push_back(*it);
		return *this;
	}

	const std::string& Curso::getCodigo() const
	{
		return codigo;
	}

	const std::string& Curso::getNome() const
	{
		return nome;
	}

	Curso::TurmasIter Curso::getTurmasBegin() const
	{
		return turmas.begin();
	}

	Curso::TurmasIter Curso::getTurmasEnd() const
	{
		return turmas.end();
	}
	
	void Curso::setCodigo(const std::string& codigo)
	{
		this->codigo = codigo;
	}

	void Curso::setNome(const std::string& nome)
	{
		this->nome = nome;
	}

	void Curso::adcionaTurma(Turma* const turma)
	{
		turmas.push_back(turma);
	}

	void Curso::removeTurma(TurmasIter turma)
	{
		turmas.erase(turma);
	}

	void Curso::save()
	{
		Banco::getInstance().save(nome_tabela, this);
	}

	void Curso::erase()
	{
		Banco::getInstance().erase(nome_tabela, this);
	}

	void Curso::sync()
	{
		Banco::getInstance().sync(nome_tabela, this);
	}
}