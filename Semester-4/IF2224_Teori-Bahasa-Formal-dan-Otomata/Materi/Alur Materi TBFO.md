```text
1. Dasar bahasa formal
2. Regular Expression
3. Finite Automata
   - DFA
   - NFA
   - ε-NFA
4. Scanner / Lexical Analyzer
5. Context-Free Grammar
6. Pushdown Automata
7. Parser / Syntax Analyzer
8. Semantic Analyzer
9. Intermediate Code Generation
10. Optimization
11. Interpreter
```

---

Secara konseptual, mata kuliah ini bisa dipahami sebagai dua jalur besar:

```text
Regular Language
    ↓
Regular Expression
    ↓
Finite Automata
    ↓
Scanner
```

dan:

```text
Context-Free Language
    ↓
Context-Free Grammar
    ↓
Pushdown Automata
    ↓
Parser
```

Lalu setelah parser selesai, masuk ke tahap compiler berikutnya:

```text
Parser
    ↓
Semantic Analyzer
    ↓
Intermediate Code Generation
    ↓
Optimization
    ↓
Interpreter / Execution
```

