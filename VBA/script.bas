Sub Main()
    MsgBox (compare_texts("aaabbbcbba", "aaabbbcbaaa", 3))
End Sub

Function compare_texts(s1 As String, s2 As String, n As Integer)
    
    Dim len1 As Integer, len2 As Integer
    Dim i As Integer, j As Integer
    
    len1 = Len(s1) - n + 1 'length of string s1
    len2 = Len(s2) - n + 1 'length of string s2
    
    ReDim symbols1(len1)
    ReDim symbols2(len2)
    
    ' split string by n elements (string to array of symbols)
    For i = 1 To len1
        symbols1(i) = Mid(s1, i, n)
    Next i
    
    ' split string by n elements (string to array of symbols)
    For i = 1 To len2
        symbols2(i) = Mid(s2, i, n)
    Next i
    
    ' dicts for saving symbols and percent comparing symbols in string
    Dim dict1
    Dim dict2
    Set dict1 = CreateObject("Scripting.Dictionary")
    Set dict2 = CreateObject("Scripting.Dictionary")
    
    Dim count As Integer
    
    ' counting percent
    For i = 1 To len1
        count = 0
        For j = 1 To len1
            If symbols1(i) = symbols1(j) Then
                count = count + 1
            End If
        Next j
        
        If Not dict1.Exists(symbols1(i)) Then
            dict1.Item(symbols1(i)) = count / len1
        End If
    Next i
    
    For i = 1 To len2
        count = 0
        For j = 1 To len2
            If symbols2(i) = symbols2(j) Then
                count = count + 1
            End If
        Next j
        
        If Not dict2.Exists(symbols2(i)) Then
            dict2.Item(symbols2(i)) = count / len2
        End If
    Next i
    
    Dim percent As Double
    percent = 0

    For Each key1 In dict1
        For Each key2 In dict2
            If key1 = key2 Then
                If dict1.Item(key1) > dict2.Item(key2) Then
                    percent = percent + dict2.Item(key2)
                Else
                    percent = percent + dict1.Item(key1)
                End If
            End If
        Next
    Next
    
    compare_texts = percent * 100
End Function

