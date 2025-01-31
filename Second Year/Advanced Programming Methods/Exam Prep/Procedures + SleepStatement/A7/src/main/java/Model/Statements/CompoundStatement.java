package Model.Statements;


import Exceptions.InterpreterException;
import Model.ProgramState.ProgramState;
import Model.Types.Type;
import Model.Collections.MyIDictionary;
import Model.Collections.MyIStack;

public class CompoundStatement implements Statement {
    private final Statement firstStatement;
    private final Statement secondStatement;

    public CompoundStatement(Statement firstStatement, Statement secondStatement) {
        this.firstStatement = firstStatement;
        this.secondStatement = secondStatement;
    }

    @Override
    public ProgramState execute(ProgramState state){
        MyIStack<Statement> stack = state.getExeStack();
        stack.push(secondStatement);
        stack.push(firstStatement);
        state.setExeStack(stack);
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws InterpreterException {
        return secondStatement.typeCheck(firstStatement.typeCheck(typeEnv));
    }

    @Override
    public Statement deepCopy() {
        return new CompoundStatement(firstStatement.deepCopy(), secondStatement.deepCopy());
    }

    @Override
    public String toString() {
        return String.format("(%s; %s)", firstStatement.toString(), secondStatement.toString());
    }
}