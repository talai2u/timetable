##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=timetable
ConfigurationName      :=Debug
WorkspacePath          :=/home/younes/poo/poo
ProjectPath            :=/home/younes/poo/poo/timetable
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Younes
Date                   :=09/01/17
CodeLitePath           :=/home/younes/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="timetable.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -L/usr/lib/mysql -lmysqlclient 
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS := -std=c++14 -std=c++11 -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/enseignant.cpp$(ObjectSuffix) $(IntermediateDirectory)/utils.cpp$(ObjectSuffix) $(IntermediateDirectory)/database.cpp$(ObjectSuffix) $(IntermediateDirectory)/niveau.cpp$(ObjectSuffix) $(IntermediateDirectory)/filiere.cpp$(ObjectSuffix) $(IntermediateDirectory)/salle.cpp$(ObjectSuffix) $(IntermediateDirectory)/cours.cpp$(ObjectSuffix) $(IntermediateDirectory)/individu.cpp$(ObjectSuffix) $(IntermediateDirectory)/administration.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/etudiant.cpp$(ObjectSuffix) $(IntermediateDirectory)/seance.cpp$(ObjectSuffix) $(IntermediateDirectory)/time_.cpp$(ObjectSuffix) $(IntermediateDirectory)/date_.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/younes/poo/poo/timetable/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix)main.cpp

$(IntermediateDirectory)/enseignant.cpp$(ObjectSuffix): enseignant.cpp $(IntermediateDirectory)/enseignant.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/younes/poo/poo/timetable/enseignant.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/enseignant.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/enseignant.cpp$(DependSuffix): enseignant.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/enseignant.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/enseignant.cpp$(DependSuffix) -MM enseignant.cpp

$(IntermediateDirectory)/enseignant.cpp$(PreprocessSuffix): enseignant.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/enseignant.cpp$(PreprocessSuffix)enseignant.cpp

$(IntermediateDirectory)/utils.cpp$(ObjectSuffix): utils.cpp $(IntermediateDirectory)/utils.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/younes/poo/poo/timetable/utils.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/utils.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/utils.cpp$(DependSuffix): utils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/utils.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/utils.cpp$(DependSuffix) -MM utils.cpp

$(IntermediateDirectory)/utils.cpp$(PreprocessSuffix): utils.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/utils.cpp$(PreprocessSuffix)utils.cpp

$(IntermediateDirectory)/database.cpp$(ObjectSuffix): database.cpp $(IntermediateDirectory)/database.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/younes/poo/poo/timetable/database.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/database.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/database.cpp$(DependSuffix): database.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/database.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/database.cpp$(DependSuffix) -MM database.cpp

$(IntermediateDirectory)/database.cpp$(PreprocessSuffix): database.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/database.cpp$(PreprocessSuffix)database.cpp

$(IntermediateDirectory)/niveau.cpp$(ObjectSuffix): niveau.cpp $(IntermediateDirectory)/niveau.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/younes/poo/poo/timetable/niveau.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/niveau.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/niveau.cpp$(DependSuffix): niveau.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/niveau.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/niveau.cpp$(DependSuffix) -MM niveau.cpp

$(IntermediateDirectory)/niveau.cpp$(PreprocessSuffix): niveau.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/niveau.cpp$(PreprocessSuffix)niveau.cpp

$(IntermediateDirectory)/filiere.cpp$(ObjectSuffix): filiere.cpp $(IntermediateDirectory)/filiere.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/younes/poo/poo/timetable/filiere.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/filiere.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/filiere.cpp$(DependSuffix): filiere.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/filiere.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/filiere.cpp$(DependSuffix) -MM filiere.cpp

$(IntermediateDirectory)/filiere.cpp$(PreprocessSuffix): filiere.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/filiere.cpp$(PreprocessSuffix)filiere.cpp

$(IntermediateDirectory)/salle.cpp$(ObjectSuffix): salle.cpp $(IntermediateDirectory)/salle.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/younes/poo/poo/timetable/salle.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/salle.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/salle.cpp$(DependSuffix): salle.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/salle.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/salle.cpp$(DependSuffix) -MM salle.cpp

$(IntermediateDirectory)/salle.cpp$(PreprocessSuffix): salle.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/salle.cpp$(PreprocessSuffix)salle.cpp

$(IntermediateDirectory)/cours.cpp$(ObjectSuffix): cours.cpp $(IntermediateDirectory)/cours.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/younes/poo/poo/timetable/cours.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cours.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cours.cpp$(DependSuffix): cours.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cours.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cours.cpp$(DependSuffix) -MM cours.cpp

$(IntermediateDirectory)/cours.cpp$(PreprocessSuffix): cours.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cours.cpp$(PreprocessSuffix)cours.cpp

$(IntermediateDirectory)/individu.cpp$(ObjectSuffix): individu.cpp $(IntermediateDirectory)/individu.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/younes/poo/poo/timetable/individu.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/individu.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/individu.cpp$(DependSuffix): individu.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/individu.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/individu.cpp$(DependSuffix) -MM individu.cpp

$(IntermediateDirectory)/individu.cpp$(PreprocessSuffix): individu.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/individu.cpp$(PreprocessSuffix)individu.cpp

$(IntermediateDirectory)/administration.cpp$(ObjectSuffix): administration.cpp $(IntermediateDirectory)/administration.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/younes/poo/poo/timetable/administration.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/administration.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/administration.cpp$(DependSuffix): administration.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/administration.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/administration.cpp$(DependSuffix) -MM administration.cpp

$(IntermediateDirectory)/administration.cpp$(PreprocessSuffix): administration.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/administration.cpp$(PreprocessSuffix)administration.cpp

$(IntermediateDirectory)/etudiant.cpp$(ObjectSuffix): etudiant.cpp $(IntermediateDirectory)/etudiant.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/younes/poo/poo/timetable/etudiant.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/etudiant.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/etudiant.cpp$(DependSuffix): etudiant.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/etudiant.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/etudiant.cpp$(DependSuffix) -MM etudiant.cpp

$(IntermediateDirectory)/etudiant.cpp$(PreprocessSuffix): etudiant.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/etudiant.cpp$(PreprocessSuffix)etudiant.cpp

$(IntermediateDirectory)/seance.cpp$(ObjectSuffix): seance.cpp $(IntermediateDirectory)/seance.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/younes/poo/poo/timetable/seance.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/seance.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/seance.cpp$(DependSuffix): seance.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/seance.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/seance.cpp$(DependSuffix) -MM seance.cpp

$(IntermediateDirectory)/seance.cpp$(PreprocessSuffix): seance.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/seance.cpp$(PreprocessSuffix)seance.cpp

$(IntermediateDirectory)/time_.cpp$(ObjectSuffix): time_.cpp $(IntermediateDirectory)/time_.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/younes/poo/poo/timetable/time_.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/time_.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/time_.cpp$(DependSuffix): time_.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/time_.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/time_.cpp$(DependSuffix) -MM time_.cpp

$(IntermediateDirectory)/time_.cpp$(PreprocessSuffix): time_.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/time_.cpp$(PreprocessSuffix)time_.cpp

$(IntermediateDirectory)/date_.cpp$(ObjectSuffix): date_.cpp $(IntermediateDirectory)/date_.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/younes/poo/poo/timetable/date_.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/date_.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/date_.cpp$(DependSuffix): date_.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/date_.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/date_.cpp$(DependSuffix) -MM date_.cpp

$(IntermediateDirectory)/date_.cpp$(PreprocessSuffix): date_.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/date_.cpp$(PreprocessSuffix)date_.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


