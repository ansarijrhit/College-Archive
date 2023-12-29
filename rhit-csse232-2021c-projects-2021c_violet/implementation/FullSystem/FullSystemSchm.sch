<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3a" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="CLK" />
        <signal name="OutputInst(15:15)" />
        <signal name="OutputInst(10:0)" />
        <signal name="OutputInst(12:0)" />
        <signal name="OutputInst(1:0)" />
        <signal name="SetID" />
        <signal name="CRWrite" />
        <signal name="OutputInst(3:0)" />
        <signal name="XLXN_67(15:0)" />
        <signal name="XLXN_68(15:0)" />
        <signal name="BSel(1:0)" />
        <signal name="ASel(1:0)" />
        <signal name="XLXN_72(15:0)" />
        <signal name="XLXN_73(15:0)" />
        <signal name="AluOp(1:0)" />
        <signal name="XLXN_84(15:0)" />
        <signal name="XLXN_85(15:0)" />
        <signal name="XLXN_132(15:0)" />
        <signal name="XLXN_133(15:0)" />
        <signal name="XLXN_135(15:0)" />
        <signal name="XLXN_138(13:0)" />
        <signal name="PCout(15:14)" />
        <signal name="opCode(4:0)" />
        <signal name="IorD" />
        <signal name="IRenable" />
        <signal name="RegWrite" />
        <signal name="MemWrite" />
        <signal name="MemRead" />
        <signal name="PCWrite" />
        <signal name="DatSel(1:0)" />
        <signal name="PCSource(1:0)" />
        <signal name="Reset" />
        <signal name="XLXN_176(15:0)" />
        <signal name="XLXN_190(15:0)" />
        <signal name="OutputInst(15:0)" />
        <signal name="Instruction(15:0)" />
        <signal name="XLXN_34(15:0)" />
        <signal name="MemDataOut(15:0)" />
        <signal name="IorDOutput(15:0)" />
        <signal name="Input(15:0)" />
        <signal name="CoolData(15:0)" />
        <signal name="PCout(15:0)" />
        <signal name="XLXN_191(15:0)" />
        <signal name="XLXN_193" />
        <signal name="Cycles(15:0)" />
        <port polarity="Input" name="CLK" />
        <port polarity="Input" name="Reset" />
        <port polarity="Input" name="Instruction(15:0)" />
        <port polarity="Input" name="MemDataOut(15:0)" />
        <port polarity="Output" name="IorDOutput(15:0)" />
        <port polarity="Input" name="Input(15:0)" />
        <port polarity="Output" name="CoolData(15:0)" />
        <port polarity="Output" name="Cycles(15:0)" />
        <blockdef name="IRCodeForSchm">
            <timestamp>2021-5-11T21:53:53</timestamp>
            <rect width="352" x="64" y="-192" height="192" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="416" y="-172" height="24" />
            <line x2="480" y1="-160" y2="-160" x1="416" />
            <rect width="64" x="416" y="-44" height="24" />
            <line x2="480" y1="-32" y2="-32" x1="416" />
        </blockdef>
        <blockdef name="coolRegFile">
            <timestamp>2021-5-18T3:12:3</timestamp>
            <line x2="0" y1="32" y2="32" x1="64" />
            <line x2="0" y1="-352" y2="-352" x1="64" />
            <rect width="64" x="0" y="-300" height="24" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="384" y="-364" height="24" />
            <line x2="448" y1="-352" y2="-352" x1="384" />
            <rect width="320" x="64" y="-384" height="448" />
        </blockdef>
        <blockdef name="RegisterFileV2">
            <timestamp>2021-5-18T3:19:14</timestamp>
            <line x2="0" y1="32" y2="32" x1="64" />
            <line x2="0" y1="-352" y2="-352" x1="64" />
            <rect width="64" x="0" y="-300" height="24" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <rect width="64" x="0" y="-172" height="24" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="432" y="-44" height="24" />
            <line x2="496" y1="-32" y2="-32" x1="432" />
            <rect width="368" x="64" y="-384" height="448" />
        </blockdef>
        <blockdef name="SignExtender">
            <timestamp>2021-5-11T21:52:37</timestamp>
            <rect width="352" x="64" y="-192" height="192" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="416" y="-172" height="24" />
            <line x2="480" y1="-160" y2="-160" x1="416" />
        </blockdef>
        <blockdef name="TwoBitMuxCode">
            <timestamp>2021-5-18T2:41:44</timestamp>
            <rect width="256" x="64" y="-320" height="320" />
            <rect width="64" x="0" y="-300" height="24" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <rect width="64" x="0" y="-236" height="24" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <rect width="64" x="0" y="-172" height="24" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-300" height="24" />
            <line x2="384" y1="-288" y2="-288" x1="320" />
        </blockdef>
        <blockdef name="constant">
            <timestamp>2006-1-1T10:10:10</timestamp>
            <rect width="112" x="0" y="0" height="64" />
            <line x2="112" y1="32" y2="32" x1="144" />
        </blockdef>
        <blockdef name="ALUCodeScm">
            <timestamp>2021-5-21T1:54:41</timestamp>
            <rect width="64" x="320" y="148" height="24" />
            <line x2="384" y1="160" y2="160" x1="320" />
            <line x2="384" y1="32" y2="32" x1="320" />
            <rect width="64" x="0" y="-172" height="24" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
            <rect width="256" x="64" y="-256" height="448" />
        </blockdef>
        <blockdef name="LeftShifter">
            <timestamp>2021-5-12T15:37:2</timestamp>
            <rect width="320" x="64" y="-64" height="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="384" y="-44" height="24" />
            <line x2="448" y1="-32" y2="-32" x1="384" />
        </blockdef>
        <blockdef name="PCALU">
            <timestamp>2021-5-19T3:3:10</timestamp>
            <line x2="0" y1="32" y2="32" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
            <rect width="256" x="64" y="-64" height="128" />
        </blockdef>
        <blockdef name="PCMux">
            <timestamp>2021-5-18T1:30:36</timestamp>
            <rect width="432" x="64" y="-256" height="256" />
            <rect width="64" x="0" y="-236" height="24" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <rect width="64" x="0" y="-172" height="24" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="496" y="-236" height="24" />
            <line x2="560" y1="-224" y2="-224" x1="496" />
        </blockdef>
        <blockdef name="PCRegister">
            <timestamp>2021-5-18T1:30:36</timestamp>
            <rect width="256" x="64" y="-256" height="256" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-236" height="24" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
        </blockdef>
        <blockdef name="PCandIR_Concatenate">
            <timestamp>2021-5-18T1:30:36</timestamp>
            <rect width="480" x="64" y="-128" height="128" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="544" y="-108" height="24" />
            <line x2="608" y1="-96" y2="-96" x1="544" />
        </blockdef>
        <blockdef name="IRLeftShift1ForPC">
            <timestamp>2021-5-18T1:30:36</timestamp>
            <rect width="336" x="64" y="-64" height="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="400" y="-44" height="24" />
            <line x2="464" y1="-32" y2="-32" x1="400" />
        </blockdef>
        <blockdef name="Control">
            <timestamp>2021-5-21T2:0:27</timestamp>
            <rect width="64" x="368" y="20" height="24" />
            <line x2="432" y1="32" y2="32" x1="368" />
            <line x2="0" y1="-800" y2="-800" x1="64" />
            <line x2="0" y1="-544" y2="-544" x1="64" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="432" y1="-800" y2="-800" x1="368" />
            <line x2="432" y1="-736" y2="-736" x1="368" />
            <line x2="432" y1="-672" y2="-672" x1="368" />
            <line x2="432" y1="-608" y2="-608" x1="368" />
            <line x2="432" y1="-544" y2="-544" x1="368" />
            <line x2="432" y1="-480" y2="-480" x1="368" />
            <line x2="432" y1="-416" y2="-416" x1="368" />
            <line x2="432" y1="-352" y2="-352" x1="368" />
            <rect width="64" x="368" y="-236" height="24" />
            <line x2="432" y1="-224" y2="-224" x1="368" />
            <rect width="64" x="368" y="-172" height="24" />
            <line x2="432" y1="-160" y2="-160" x1="368" />
            <rect width="64" x="368" y="-108" height="24" />
            <line x2="432" y1="-96" y2="-96" x1="368" />
            <rect width="64" x="368" y="-44" height="24" />
            <line x2="432" y1="-32" y2="-32" x1="368" />
            <rect width="304" x="64" y="-832" height="896" />
        </blockdef>
        <blockdef name="OneBitMux">
            <timestamp>2021-5-18T2:21:8</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-172" height="24" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
        </blockdef>
        <blockdef name="CycleCounter">
            <timestamp>2021-5-21T2:57:33</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-108" height="24" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
        </blockdef>
        <block symbolname="SignExtender" name="XLXI_4">
            <blockpin signalname="OutputInst(15:15)" name="IR_msb" />
            <blockpin signalname="OutputInst(10:0)" name="IR_immediate(10:0)" />
            <blockpin signalname="OutputInst(12:0)" name="IR_branch(12:0)" />
            <blockpin signalname="XLXN_68(15:0)" name="SEOUT(15:0)" />
        </block>
        <block symbolname="coolRegFile" name="XLXI_2">
            <blockpin signalname="Reset" name="Reset" />
            <blockpin signalname="CLK" name="CLK" />
            <blockpin signalname="XLXN_190(15:0)" name="DataIn(15:0)" />
            <blockpin signalname="CRWrite" name="CRW" />
            <blockpin signalname="OutputInst(1:0)" name="CrAddr(1:0)" />
            <blockpin signalname="SetID" name="SetID" />
            <blockpin signalname="XLXN_34(15:0)" name="CoolData(15:0)" />
        </block>
        <block symbolname="RegisterFileV2" name="XLXI_11">
            <blockpin signalname="RegWrite" name="Write" />
            <blockpin signalname="OutputInst(3:0)" name="WriteAddr(3:0)" />
            <blockpin signalname="CLK" name="CLK" />
            <blockpin signalname="XLXN_190(15:0)" name="DataIn(15:0)" />
            <blockpin signalname="OutputInst(3:0)" name="ReadAddrA(3:0)" />
            <blockpin signalname="XLXN_67(15:0)" name="ReadDataA(15:0)" />
            <blockpin signalname="Reset" name="Reset" />
        </block>
        <block symbolname="TwoBitMuxCode" name="XLXI_24">
            <blockpin signalname="ASel(1:0)" name="Selector(1:0)" />
            <blockpin signalname="XLXN_133(15:0)" name="A(15:0)" />
            <blockpin signalname="XLXN_67(15:0)" name="B(15:0)" />
            <blockpin signalname="XLXN_34(15:0)" name="C(15:0)" />
            <blockpin signalname="XLXN_84(15:0)" name="D(15:0)" />
            <blockpin signalname="XLXN_73(15:0)" name="Output(15:0)" />
        </block>
        <block symbolname="TwoBitMuxCode" name="XLXI_20">
            <blockpin signalname="BSel(1:0)" name="Selector(1:0)" />
            <blockpin signalname="XLXN_67(15:0)" name="A(15:0)" />
            <blockpin signalname="XLXN_34(15:0)" name="B(15:0)" />
            <blockpin signalname="XLXN_68(15:0)" name="C(15:0)" />
            <blockpin signalname="XLXN_85(15:0)" name="D(15:0)" />
            <blockpin signalname="XLXN_72(15:0)" name="Output(15:0)" />
        </block>
        <block symbolname="ALUCodeScm" name="XLXI_33">
            <blockpin signalname="XLXN_73(15:0)" name="a(15:0)" />
            <blockpin signalname="XLXN_72(15:0)" name="b(15:0)" />
            <blockpin signalname="AluOp(1:0)" name="s(1:0)" />
            <blockpin signalname="XLXN_193" name="z" />
            <blockpin signalname="XLXN_176(15:0)" name="o(15:0)" />
            <blockpin signalname="XLXN_191(15:0)" name="g(15:0)" />
        </block>
        <block symbolname="constant" name="XLXI_35">
            <attr value="0" name="CValue">
                <trait delete="all:1 sym:0" />
                <trait editname="all:1 sch:0" />
                <trait valuetype="BitVector 32 Hexadecimal" />
            </attr>
            <blockpin signalname="XLXN_84(15:0)" name="O" />
        </block>
        <block symbolname="LeftShifter" name="XLXI_36">
            <blockpin signalname="XLXN_68(15:0)" name="inputVal(15:0)" />
            <blockpin signalname="XLXN_85(15:0)" name="ShiftedVal(15:0)" />
        </block>
        <block symbolname="PCALU" name="XLXI_47">
            <blockpin signalname="PCout(15:0)" name="PCIN(15:0)" />
            <blockpin signalname="XLXN_133(15:0)" name="PCOUT(15:0)" />
            <blockpin signalname="CLK" name="CLK" />
        </block>
        <block symbolname="PCMux" name="XLXI_48">
            <blockpin signalname="XLXN_176(15:0)" name="ALUPC(15:0)" />
            <blockpin signalname="XLXN_135(15:0)" name="ConcatenatedPC(15:0)" />
            <blockpin signalname="XLXN_133(15:0)" name="PCincrement(15:0)" />
            <blockpin signalname="PCSource(1:0)" name="s(1:0)" />
            <blockpin signalname="XLXN_132(15:0)" name="SelectedPC(15:0)" />
        </block>
        <block symbolname="PCRegister" name="XLXI_49">
            <blockpin signalname="CLK" name="CLK" />
            <blockpin signalname="PCWrite" name="PCWrite" />
            <blockpin signalname="Reset" name="Reset" />
            <blockpin signalname="XLXN_132(15:0)" name="PCIn(15:0)" />
            <blockpin signalname="PCout(15:0)" name="PCout(15:0)" />
        </block>
        <block symbolname="PCandIR_Concatenate" name="XLXI_50">
            <blockpin signalname="XLXN_138(13:0)" name="LeftShiftedIR(13:0)" />
            <blockpin signalname="PCout(15:14)" name="TwoBitsPC(1:0)" />
            <blockpin signalname="XLXN_135(15:0)" name="ConcatenatedOutput(15:0)" />
        </block>
        <block symbolname="IRLeftShift1ForPC" name="XLXI_51">
            <blockpin signalname="OutputInst(12:0)" name="IR(12:0)" />
            <blockpin signalname="XLXN_138(13:0)" name="LeftShiftedOutput(13:0)" />
        </block>
        <block symbolname="Control" name="XLXI_52">
            <blockpin signalname="CLK" name="CLK" />
            <blockpin signalname="Reset" name="Reset" />
            <blockpin signalname="XLXN_193" name="z" />
            <blockpin signalname="opCode(4:0)" name="OPcode(4:0)" />
            <blockpin signalname="IorD" name="IorD" />
            <blockpin signalname="IRenable" name="IRenable" />
            <blockpin signalname="SetID" name="SetID" />
            <blockpin signalname="CRWrite" name="CRWrite" />
            <blockpin signalname="RegWrite" name="RegWrite" />
            <blockpin signalname="MemWrite" name="MemWrite" />
            <blockpin signalname="MemRead" name="MemRead" />
            <blockpin signalname="PCWrite" name="PCwrite" />
            <blockpin signalname="PCSource(1:0)" name="PCSource(1:0)" />
            <blockpin signalname="AluOp(1:0)" name="ALUOp(1:0)" />
            <blockpin signalname="ASel(1:0)" name="Asel(1:0)" />
            <blockpin signalname="BSel(1:0)" name="Bsel(1:0)" />
            <blockpin signalname="DatSel(1:0)" name="DatSel(1:0)" />
        </block>
        <block symbolname="OneBitMux" name="XLXI_56">
            <blockpin signalname="IorD" name="Selector" />
            <blockpin signalname="PCout(15:0)" name="A(15:0)" />
            <blockpin signalname="XLXN_176(15:0)" name="B(15:0)" />
            <blockpin signalname="IorDOutput(15:0)" name="Output(15:0)" />
        </block>
        <block symbolname="IRCodeForSchm" name="XLXI_5">
            <blockpin signalname="IRenable" name="enable" />
            <blockpin signalname="CLK" name="CLK" />
            <blockpin signalname="Instruction(15:0)" name="Instruction(15:0)" />
            <blockpin signalname="OutputInst(15:0)" name="OutputInst(15:0)" />
            <blockpin signalname="opCode(4:0)" name="opCode(4:0)" />
        </block>
        <block symbolname="TwoBitMuxCode" name="XLXI_57">
            <blockpin signalname="DatSel(1:0)" name="Selector(1:0)" />
            <blockpin signalname="MemDataOut(15:0)" name="A(15:0)" />
            <blockpin signalname="XLXN_176(15:0)" name="B(15:0)" />
            <blockpin signalname="Input(15:0)" name="C(15:0)" />
            <blockpin signalname="XLXN_191(15:0)" name="D(15:0)" />
            <blockpin signalname="XLXN_190(15:0)" name="Output(15:0)" />
        </block>
        <block symbolname="CycleCounter" name="XLXI_58">
            <blockpin signalname="CLK" name="CLK" />
            <blockpin signalname="Reset" name="Reset" />
            <blockpin signalname="Cycles(15:0)" name="CycleCount(15:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="7040" height="5440">
        <instance x="4016" y="2096" name="XLXI_4" orien="R0">
        </instance>
        <branch name="OutputInst(15:15)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="3968" y="1936" type="branch" />
            <wire x2="4016" y1="1936" y2="1936" x1="3968" />
        </branch>
        <branch name="OutputInst(10:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="3968" y="2000" type="branch" />
            <wire x2="4016" y1="2000" y2="2000" x1="3968" />
        </branch>
        <branch name="OutputInst(12:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="3968" y="2064" type="branch" />
            <wire x2="4016" y1="2064" y2="2064" x1="3968" />
        </branch>
        <instance x="4128" y="1584" name="XLXI_2" orien="R0">
        </instance>
        <branch name="CLK">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="4064" y="1232" type="branch" />
            <wire x2="4128" y1="1232" y2="1232" x1="4064" />
        </branch>
        <branch name="OutputInst(1:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="4064" y="1488" type="branch" />
            <wire x2="4128" y1="1488" y2="1488" x1="4064" />
        </branch>
        <instance x="4032" y="928" name="XLXI_11" orien="R0">
        </instance>
        <branch name="CLK">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="3984" y="704" type="branch" />
            <wire x2="4032" y1="704" y2="704" x1="3984" />
        </branch>
        <branch name="OutputInst(3:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="4000" y="832" type="branch" />
            <wire x2="4032" y1="832" y2="832" x1="4000" />
        </branch>
        <branch name="OutputInst(3:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="3968" y="640" type="branch" />
            <wire x2="4032" y1="640" y2="640" x1="3968" />
        </branch>
        <instance x="5200" y="832" name="XLXI_24" orien="R0">
        </instance>
        <instance x="5232" y="1392" name="XLXI_20" orien="R0">
        </instance>
        <branch name="XLXN_67(15:0)">
            <wire x2="4768" y1="896" y2="896" x1="4528" />
            <wire x2="4768" y1="672" y2="896" x1="4768" />
            <wire x2="4912" y1="672" y2="672" x1="4768" />
            <wire x2="5200" y1="672" y2="672" x1="4912" />
            <wire x2="4912" y1="672" y2="1168" x1="4912" />
            <wire x2="5232" y1="1168" y2="1168" x1="4912" />
        </branch>
        <branch name="XLXN_68(15:0)">
            <wire x2="4864" y1="1936" y2="1936" x1="4496" />
            <wire x2="5232" y1="1296" y2="1296" x1="4864" />
            <wire x2="4864" y1="1296" y2="1776" x1="4864" />
            <wire x2="4992" y1="1776" y2="1776" x1="4864" />
            <wire x2="4864" y1="1776" y2="1936" x1="4864" />
        </branch>
        <branch name="BSel(1:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="5200" y="1104" type="branch" />
            <wire x2="5232" y1="1104" y2="1104" x1="5200" />
        </branch>
        <instance x="5872" y="992" name="XLXI_33" orien="R0">
        </instance>
        <branch name="XLXN_72(15:0)">
            <wire x2="5744" y1="1104" y2="1104" x1="5616" />
            <wire x2="5744" y1="896" y2="1104" x1="5744" />
            <wire x2="5872" y1="896" y2="896" x1="5744" />
        </branch>
        <branch name="XLXN_73(15:0)">
            <wire x2="5728" y1="544" y2="544" x1="5584" />
            <wire x2="5728" y1="544" y2="832" x1="5728" />
            <wire x2="5872" y1="832" y2="832" x1="5728" />
        </branch>
        <branch name="XLXN_84(15:0)">
            <wire x2="5200" y1="800" y2="800" x1="5072" />
        </branch>
        <instance x="4928" y="768" name="XLXI_35" orien="R0">
        </instance>
        <branch name="XLXN_85(15:0)">
            <wire x2="5232" y1="1360" y2="1360" x1="5216" />
            <wire x2="5216" y1="1360" y2="1456" x1="5216" />
            <wire x2="5504" y1="1456" y2="1456" x1="5216" />
            <wire x2="5504" y1="1456" y2="1776" x1="5504" />
            <wire x2="5504" y1="1776" y2="1776" x1="5440" />
        </branch>
        <instance x="4992" y="1808" name="XLXI_36" orien="R0">
        </instance>
        <instance x="1552" y="528" name="XLXI_50" orien="R0">
        </instance>
        <instance x="1856" y="272" name="XLXI_51" orien="R0">
        </instance>
        <instance x="2528" y="560" name="XLXI_48" orien="R0">
        </instance>
        <instance x="1616" y="720" name="XLXI_47" orien="R0">
        </instance>
        <instance x="1584" y="1168" name="XLXI_49" orien="R0">
        </instance>
        <branch name="XLXN_132(15:0)">
            <wire x2="1552" y1="1136" y2="1264" x1="1552" />
            <wire x2="2240" y1="1264" y2="1264" x1="1552" />
            <wire x2="1584" y1="1136" y2="1136" x1="1552" />
            <wire x2="2240" y1="992" y2="1264" x1="2240" />
            <wire x2="3104" y1="992" y2="992" x1="2240" />
            <wire x2="3104" y1="336" y2="336" x1="3088" />
            <wire x2="3104" y1="336" y2="992" x1="3104" />
        </branch>
        <branch name="XLXN_138(13:0)">
            <wire x2="1536" y1="304" y2="432" x1="1536" />
            <wire x2="1552" y1="432" y2="432" x1="1536" />
            <wire x2="2336" y1="304" y2="304" x1="1536" />
            <wire x2="2336" y1="240" y2="240" x1="2320" />
            <wire x2="2336" y1="240" y2="304" x1="2336" />
        </branch>
        <branch name="PCout(15:14)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="1488" y="496" type="branch" />
            <wire x2="1552" y1="496" y2="496" x1="1488" />
        </branch>
        <branch name="XLXN_133(15:0)">
            <wire x2="2432" y1="688" y2="688" x1="2000" />
            <wire x2="3568" y1="688" y2="688" x1="2432" />
            <wire x2="2528" y1="464" y2="464" x1="2432" />
            <wire x2="2432" y1="464" y2="688" x1="2432" />
            <wire x2="3568" y1="336" y2="688" x1="3568" />
            <wire x2="4896" y1="336" y2="336" x1="3568" />
            <wire x2="4896" y1="336" y2="608" x1="4896" />
            <wire x2="5200" y1="608" y2="608" x1="4896" />
        </branch>
        <branch name="CLK">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="1504" y="944" type="branch" />
            <wire x2="1584" y1="944" y2="944" x1="1504" />
        </branch>
        <branch name="PCWrite">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="1504" y="1008" type="branch" />
            <wire x2="1584" y1="1008" y2="1008" x1="1504" />
        </branch>
        <branch name="Reset">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="1504" y="1072" type="branch" />
            <wire x2="1584" y1="1072" y2="1072" x1="1504" />
        </branch>
        <instance x="1600" y="3088" name="XLXI_52" orien="R0">
        </instance>
        <branch name="IorD">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2144" y="2288" type="branch" />
            <wire x2="2144" y1="2288" y2="2288" x1="2032" />
        </branch>
        <branch name="IRenable">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2144" y="2352" type="branch" />
            <wire x2="2144" y1="2352" y2="2352" x1="2032" />
        </branch>
        <branch name="SetID">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2144" y="2416" type="branch" />
            <wire x2="2144" y1="2416" y2="2416" x1="2032" />
        </branch>
        <branch name="CRWrite">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2144" y="2480" type="branch" />
            <wire x2="2144" y1="2480" y2="2480" x1="2032" />
        </branch>
        <branch name="RegWrite">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2144" y="2544" type="branch" />
            <wire x2="2144" y1="2544" y2="2544" x1="2032" />
        </branch>
        <branch name="MemWrite">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2144" y="2608" type="branch" />
            <wire x2="2144" y1="2608" y2="2608" x1="2032" />
        </branch>
        <branch name="MemRead">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2144" y="2672" type="branch" />
            <wire x2="2144" y1="2672" y2="2672" x1="2032" />
        </branch>
        <branch name="PCWrite">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2144" y="2736" type="branch" />
            <wire x2="2144" y1="2736" y2="2736" x1="2032" />
        </branch>
        <branch name="PCSource(1:0)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2144" y="2864" type="branch" />
            <wire x2="2144" y1="2864" y2="2864" x1="2032" />
        </branch>
        <branch name="AluOp(1:0)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2144" y="2928" type="branch" />
            <wire x2="2144" y1="2928" y2="2928" x1="2032" />
        </branch>
        <branch name="ASel(1:0)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2144" y="2992" type="branch" />
            <wire x2="2144" y1="2992" y2="2992" x1="2032" />
        </branch>
        <branch name="BSel(1:0)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2144" y="3056" type="branch" />
            <wire x2="2144" y1="3056" y2="3056" x1="2032" />
        </branch>
        <branch name="opCode(4:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="1520" y="3056" type="branch" />
            <wire x2="1600" y1="3056" y2="3056" x1="1520" />
        </branch>
        <branch name="Reset">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="1520" y="2544" type="branch" />
            <wire x2="1600" y1="2544" y2="2544" x1="1520" />
        </branch>
        <branch name="CLK">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="1520" y="2288" type="branch" />
            <wire x2="1600" y1="2288" y2="2288" x1="1520" />
        </branch>
        <branch name="CLK">
            <wire x2="816" y1="2160" y2="2160" x1="688" />
        </branch>
        <iomarker fontsize="28" x="688" y="2160" name="CLK" orien="R180" />
        <branch name="Reset">
            <wire x2="832" y1="2272" y2="2272" x1="704" />
        </branch>
        <iomarker fontsize="28" x="704" y="2272" name="Reset" orien="R180" />
        <branch name="OutputInst(12:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="1808" y="240" type="branch" />
            <wire x2="1856" y1="240" y2="240" x1="1808" />
        </branch>
        <branch name="CRWrite">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="4064" y="1360" type="branch" />
            <wire x2="4128" y1="1360" y2="1360" x1="4064" />
        </branch>
        <branch name="SetID">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="4064" y="1552" type="branch" />
            <wire x2="4128" y1="1552" y2="1552" x1="4064" />
        </branch>
        <branch name="RegWrite">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="3968" y="576" type="branch" />
            <wire x2="4032" y1="576" y2="576" x1="3968" />
        </branch>
        <branch name="ASel(1:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="5136" y="544" type="branch" />
            <wire x2="5200" y1="544" y2="544" x1="5136" />
        </branch>
        <branch name="AluOp(1:0)">
            <attrtext style="alignment:SOFT-VRIGHT;fontsize:28;fontname:Arial" attrname="Name" x="5824" y="1040" type="branch" />
            <wire x2="5872" y1="960" y2="960" x1="5824" />
            <wire x2="5824" y1="960" y2="1040" x1="5824" />
        </branch>
        <instance x="320" y="992" name="XLXI_56" orien="R0">
        </instance>
        <branch name="IorD">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="208" y="832" type="branch" />
            <wire x2="320" y1="832" y2="832" x1="208" />
        </branch>
        <branch name="XLXN_176(15:0)">
            <wire x2="2512" y1="96" y2="96" x1="48" />
            <wire x2="2512" y1="96" y2="336" x1="2512" />
            <wire x2="2528" y1="336" y2="336" x1="2512" />
            <wire x2="6400" y1="96" y2="96" x1="2512" />
            <wire x2="6400" y1="96" y2="960" x1="6400" />
            <wire x2="6400" y1="960" y2="2288" x1="6400" />
            <wire x2="48" y1="96" y2="960" x1="48" />
            <wire x2="320" y1="960" y2="960" x1="48" />
            <wire x2="2992" y1="1504" y2="2288" x1="2992" />
            <wire x2="6400" y1="2288" y2="2288" x1="2992" />
            <wire x2="3072" y1="1504" y2="1504" x1="2992" />
            <wire x2="6400" y1="960" y2="960" x1="6256" />
        </branch>
        <branch name="XLXN_190(15:0)">
            <wire x2="3568" y1="1376" y2="1376" x1="3456" />
            <wire x2="3792" y1="1376" y2="1376" x1="3568" />
            <wire x2="4032" y1="768" y2="768" x1="3568" />
            <wire x2="3568" y1="768" y2="1376" x1="3568" />
            <wire x2="3792" y1="1296" y2="1376" x1="3792" />
            <wire x2="4128" y1="1296" y2="1296" x1="3792" />
        </branch>
        <branch name="OutputInst(15:0)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="1888" y="1664" type="branch" />
            <wire x2="1888" y1="1664" y2="1664" x1="1856" />
        </branch>
        <branch name="opCode(4:0)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="1904" y="1792" type="branch" />
            <wire x2="1904" y1="1792" y2="1792" x1="1856" />
        </branch>
        <branch name="Instruction(15:0)">
            <wire x2="1376" y1="1792" y2="1792" x1="1328" />
        </branch>
        <branch name="CLK">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="1328" y="1728" type="branch" />
            <wire x2="1376" y1="1728" y2="1728" x1="1328" />
        </branch>
        <instance x="1376" y="1824" name="XLXI_5" orien="R0">
        </instance>
        <branch name="IRenable">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="1328" y="1664" type="branch" />
            <wire x2="1376" y1="1664" y2="1664" x1="1328" />
        </branch>
        <iomarker fontsize="28" x="1328" y="1792" name="Instruction(15:0)" orien="R180" />
        <branch name="XLXN_34(15:0)">
            <wire x2="4784" y1="1232" y2="1232" x1="4576" />
            <wire x2="5232" y1="1232" y2="1232" x1="4784" />
            <wire x2="5200" y1="736" y2="736" x1="4784" />
            <wire x2="4784" y1="736" y2="1232" x1="4784" />
        </branch>
        <branch name="IorDOutput(15:0)">
            <wire x2="752" y1="832" y2="832" x1="704" />
        </branch>
        <iomarker fontsize="28" x="752" y="832" name="IorDOutput(15:0)" orien="R0" />
        <branch name="PCSource(1:0)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2528" y="592" type="branch" />
            <wire x2="2528" y1="528" y2="528" x1="2512" />
            <wire x2="2512" y1="528" y2="592" x1="2512" />
            <wire x2="2528" y1="592" y2="592" x1="2512" />
        </branch>
        <branch name="Reset">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="4048" y="1616" type="branch" />
            <wire x2="4128" y1="1616" y2="1616" x1="4048" />
        </branch>
        <branch name="Reset">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="3984" y="960" type="branch" />
            <wire x2="4032" y1="960" y2="960" x1="3984" />
        </branch>
        <branch name="CLK">
            <attrtext style="alignment:SOFT-VRIGHT;fontsize:28;fontname:Arial" attrname="Name" x="1520" y="784" type="branch" />
            <wire x2="1616" y1="752" y2="752" x1="1520" />
            <wire x2="1520" y1="752" y2="784" x1="1520" />
        </branch>
        <instance x="3072" y="1664" name="XLXI_57" orien="R0">
        </instance>
        <branch name="DatSel(1:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="2960" y="1376" type="branch" />
            <wire x2="3072" y1="1376" y2="1376" x1="2960" />
        </branch>
        <branch name="MemDataOut(15:0)">
            <wire x2="3072" y1="1440" y2="1440" x1="2976" />
        </branch>
        <iomarker fontsize="28" x="2976" y="1440" name="MemDataOut(15:0)" orien="R180" />
        <branch name="Input(15:0)">
            <wire x2="3072" y1="1568" y2="1568" x1="2816" />
        </branch>
        <iomarker fontsize="28" x="2816" y="1568" name="Input(15:0)" orien="R180" />
        <branch name="CoolData(15:0)">
            <wire x2="6672" y1="320" y2="320" x1="6528" />
        </branch>
        <iomarker fontsize="28" x="6672" y="320" name="CoolData(15:0)" orien="R0" />
        <text x="6516" y="252">Always outputs, used as output data from processor</text>
        <branch name="DatSel(1:0)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2176" y="3120" type="branch" />
            <wire x2="2176" y1="3120" y2="3120" x1="2032" />
        </branch>
        <branch name="XLXN_135(15:0)">
            <wire x2="2336" y1="432" y2="432" x1="2160" />
            <wire x2="2528" y1="400" y2="400" x1="2336" />
            <wire x2="2336" y1="400" y2="432" x1="2336" />
        </branch>
        <branch name="PCout(15:0)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2032" y="944" type="branch" />
            <wire x2="2032" y1="944" y2="944" x1="1968" />
        </branch>
        <branch name="PCout(15:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="1552" y="688" type="branch" />
            <wire x2="1616" y1="688" y2="688" x1="1552" />
        </branch>
        <branch name="PCout(15:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="288" y="896" type="branch" />
            <wire x2="320" y1="896" y2="896" x1="288" />
        </branch>
        <branch name="XLXN_191(15:0)">
            <wire x2="3072" y1="1632" y2="1632" x1="3040" />
            <wire x2="3040" y1="1632" y2="2480" x1="3040" />
            <wire x2="6256" y1="2480" y2="2480" x1="3040" />
            <wire x2="6256" y1="1152" y2="2480" x1="6256" />
        </branch>
        <branch name="XLXN_193">
            <wire x2="1600" y1="2800" y2="2800" x1="1280" />
            <wire x2="1280" y1="2800" y2="3376" x1="1280" />
            <wire x2="6336" y1="3376" y2="3376" x1="1280" />
            <wire x2="6336" y1="1024" y2="1024" x1="6256" />
            <wire x2="6336" y1="1024" y2="3376" x1="6336" />
        </branch>
        <instance x="1776" y="4304" name="XLXI_58" orien="R0">
        </instance>
        <branch name="CLK">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="1664" y="4208" type="branch" />
            <wire x2="1776" y1="4208" y2="4208" x1="1664" />
        </branch>
        <branch name="Reset">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="1664" y="4272" type="branch" />
            <wire x2="1776" y1="4272" y2="4272" x1="1664" />
        </branch>
        <branch name="Cycles(15:0)">
            <wire x2="2256" y1="4208" y2="4208" x1="2160" />
        </branch>
        <iomarker fontsize="28" x="2256" y="4208" name="Cycles(15:0)" orien="R0" />
    </sheet>
</drawing>