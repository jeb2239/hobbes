//
// Created by barriosj on 7/10/17.
//

#ifndef HOBBES_EVALUATOR_H
#define HOBBES_EVALUATOR_H

#include <hobbes/hobbes.H>
#include "www.H"

namespace hc {

    typedef std::vector<std::string> ModuleFiles;

    struct Args {
        typedef std::map<std::string, std::string> NameVals;

        ModuleFiles  mfiles;
        std::string  evalExpr;
        bool         showDbg;
        bool         useDefColors;
        bool         silent;
        int          replPort;
        int          httpdPort;
        bool         exitAfterEval;
        NameVals     scriptNameVals;
        bool         machineREPL;    // should we structure console I/O for machine-reading?

        Args() : useDefColors(false), silent(false), replPort(-1), httpdPort(-1), exitAfterEval(false), machineREPL(false) {
        }
    };

    class evaluator {
    public:
        evaluator(const Args&);
        ~evaluator();

        void runMachineREPL();

        // support the 'evaluator' interface on a local compiler context
        void showClass(const std::string& cname);
        void showInstances(const std::string& cname);

        void loadModule(const std::string& mfile);

        void evalExpr(const std::string& expr);
        void printUnsweetenedExpr(const std::string& expr);
        void printTypeOf(const std::string& expr, bool);

        void printTypeEnv();
        void lookupFunction();
        hobbes::str::seq completionsFor(const std::string& prefix) const;
        void printLLVMModule();
        void printLLVMModule(int n);
        void mergeModules();
        void printAssembly(const std::string& expr, void (*)(void*,size_t));
        void perfTestExpr(const std::string& expr);
        void breakdownEvalExpr(const std::string& expr);
        void resetREPLCycle();
    private:
        hobbes::cc ctx;
        bool       silent;
        WWWServer* wwwd;
    };

}


#endif //HOBBES_EVALUATOR_H
