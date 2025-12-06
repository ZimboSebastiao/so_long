# So Long 


<div align="center">

![So Long](https://img.shields.io/badge/42-São_Paulo-0056D2?style=for-the-badge&logo=42&logoColor=white)
![Language](https://img.shields.io/badge/C-A8B9CC?style=for-the-badge&logo=c&logoColor=black)
![License](https://img.shields.io/badge/License-MIT-32CD32?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)
![Version](https://img.shields.io/badge/Version-1.0.0-blue?style=for-the-badge)

</div>

<div align="center">

![GitHub repo size](https://img.shields.io/github/repo-size/ZimboSebastiao/so_long?style=flat-square&color=0056D2)
![GitHub last commit](https://img.shields.io/github/last-commit/ZimboSebastiao/so_long?style=flat-square&color=32CD32)
![GitHub issues](https://img.shields.io/github/issues/ZimboSebastiao/so_long?style=flat-square&color=orange)

</div>

## 🎮 Sobre o Projeto

So Long é um projeto da 42 São Paulo que consiste em desenvolver um jogo 2D usando a MiniLibX. Neste jogo, você controla um peixe que deve coletar todos os cristais de gelo para abrir a saída e escapar, enquanto evita inimigos mortais que patrulham o cenário.


<br>

## 🎥 Demonstração

📹 **Vídeo de Demonstração**: [demo](./video/demo.webm)

*Demonstração do jogo funcionando com todas as mecânicas*

<br>



## 🚀 Funcionalidades

- ✅ **Mapa Validado**: Sistema de validação rigoroso para arquivos `.ber`
- ✅ **Movimentação Suave**: Controles responsivos com animação do personagem
- ✅ **Sistema de Coletáveis**: Colete todos os cristais para abrir a saída
- ✅ **Inimigos Inteligentes**: Armadilhas que se movem automaticamente
- ✅ **Múltiplas Sprites**: Animação de personagem e armadilhas
- ✅ **Contador de Movimentos**: Exibe o número de movimentos na tela
- ✅ **Sistema de Vitória/Derrota**: Mensagens claras e encerramento adequado

## 🎯 Regras do Jogo

### Elementos do Mapa:
- **`0`** - Espaço vazio (chão)
- **`1`** - Parede
- **`P`** - Jogador (peixe)
- **`C`** - Cristal coletável
- **`E`** - Saída
- **`T`** - Armadilha/inimigo

### Objetivo:
1. Coletar **todos os cristais (C)** do mapa
2. A saída (**E**) se abre automaticamente quando todos os cristais são coletados
3. Chegar à saída para vencer o jogo
4. Evitar contato com as armadilhas (**T**) que se movem automaticamente

### Controles:
- **W** ou **↑** - Mover para cima
- **S** ou **↓** - Mover para baixo
- **A** ou **←** - Mover para esquerda
- **D** ou **→** - Mover para direita
- **ESC** - Sair do jogo
- **Clique no X** - Fechar janela

## 🔧 Requisitos e Instalação

### Dependências:
- **GCC** (compilador C)
- **Make**
- **MiniLibX** (já incluída no projeto)
- **Linux/Unix** (testado em sistemas Linux)

### Compilação:
```bash
# Compile o projeto
make

# Ou compile com regras específicas
make all      # Compila tudo
make clean    # Remove arquivos objeto
make fclean   # Remove arquivos objeto e executável
make re       # Recompila completamente
```

<br>

## 🎮 Como Executar

#### Execute o jogo com um mapa

```bash
./so_long maps/map.ber
```

#### Execute com valgrind para verificar memory leaks

```bash
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/map.ber
```

#### Execute com diferentes mapas
```bash
./so_long maps/hard.ber
./so_long maps/big_map.ber
```

## Debug e Verificação

#### Com valgrind:
```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long maps/map.ber
```

<div align="center">
</div>
<div align="center">
  
---
  
</div>

<!-- Footer -->
<div align="center">

### 📞 Contato

[![Email](https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:gloriasebastiao7@gmail.com)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/zimbo-sebasti%C3%A3o-3397a1195/)


### 🌟 Dê uma estrela!

Se este projeto foi útil para você, considere dar uma estrela ⭐

[![GitHub stars](https://img.shields.io/github/stars/ZimboSebastiao/so_long?style=social)](https://github.com/ZimboSebastiao/so_long)

### 📄 Licença

Este projeto está licenciado sob a Licença MIT - veja o arquivo [LICENSE](LICENSE) para detalhes.

---

**So Long** • Projeto 42 São Paulo • Desenvolvido com 💙

</div>