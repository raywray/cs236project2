cmake_minimum_required(VERSION 3.19)
project(Project1_Starter_Code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project1_Starter_Code
        Automaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        Lexer.cpp
        Lexer.h
        main.cpp
        Token.cpp
        Token.h Comma.cpp Comma.h LeftParen.cpp LeftParen.h RightParen.cpp RightParen.h Period.cpp Period.h QMark.cpp QMark.h Multiply.cpp Multiply.h Add.cpp Add.h Schemes.cpp Schemes.h Facts.cpp Facts.h Rules.cpp Rules.h Queries.cpp Queries.h ID.cpp ID.h Comment.cpp Comment.h EOF.cpp EOF.h StringAuto.cpp StringAuto.h Undefined.cpp Undefined.h)
