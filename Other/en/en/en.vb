Imports System.Console
Module Module1
    Sub Main()
        Console.WriteLine("Please enter the distance in inches")
        Do While (True)
            Try
                Dim D As Integer
                Dim C As Decimal = "12.9590697"
                Dim Wr As Decimal
                Dim Ma As Decimal = 2 / 3
                Dim Mr As Decimal
                Dim Mt As Decimal = "627.2"
                Dim E
                Console.Write("> ")
                D = Console.ReadLine()
                Console.WriteLine("Computing...")
                Wr = D / C
                Mr = Wr / Ma
                E = Mr * Mt
                Console.WriteLine("Encoder Tics: " & E)
            Catch
                Console.WriteLine("Error (" & Err.Number & ") " & Err.Description)
            End Try
        Loop
    End Sub
End Module
