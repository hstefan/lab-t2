#ifndef HUGO_SECONDARY_DATA_H_
#define HUGO_SECONDARY_DATA_H_

#include <string>

namespace aux
{
	struct Endereco
	{
		std::string rua, bairro, cidade, estado, pais;
		unsigned int cep, num_casa;

		Endereco(const std::string& rua, const std::string& bairro, const std::string& cidade, const std::string& estado,
			const std::string& pais, unsigned int cep, unsigned int num_casa);
	};
}

#endif